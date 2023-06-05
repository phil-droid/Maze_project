#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Define constants

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const float FOV = 60.0f;
int MAP_WIDTH = 0;
int MAP_HEIGHT = 0;
std::vector<std::vector<int>> worldMap;

float playerX = 3.0f;
float playerY = 3.0f;
float playerAngle = 0.0f;

bool drawMapEnabled = false;
bool isRaining = false;

float wrapAngle(float angle)
{
    while (angle < 0)
        angle += 360;
    while (angle >= 360)
        angle -= 360;
    return angle;
}

void cleanupMap()
{
    worldMap.clear();
}

bool parseMap(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (!file)
    {
        std::cerr << "Failed to open map file: " << filePath << std::endl;
        return false;
    }

    file >> MAP_WIDTH >> MAP_HEIGHT;
    if (MAP_WIDTH <= 0 || MAP_HEIGHT <= 0)
    {
        std::cerr << "Invalid map dimensions" << std::endl;
        file.close();
        return false;
    }

    cleanupMap();

    worldMap.resize(MAP_WIDTH, std::vector<int>(MAP_HEIGHT));

    for (int y = 0; y < MAP_HEIGHT; ++y)
    {
        for (int x = 0; x < MAP_WIDTH; ++x)
        {
            if (!(file >> worldMap[x][y]))
            {
                std::cerr << "Failed to read map data at position (" << x << ", " << y << ")." << std::endl;
                file.close();
                cleanupMap();
                return false;
            }
            else
            {
                std::cout << "Read map value at position (" << x << ", " << y << "): " << worldMap[x][y] << std::endl;
            }
        }
    }

    file.close();
    return true;
}

bool checkCollision(float newPlayerX, float newPlayerY)
{
    int cellX = static_cast<int>(newPlayerX);
    int cellY = static_cast<int>(newPlayerY);

    if (cellX < 0 || cellX >= MAP_WIDTH || cellY < 0 || cellY >= MAP_HEIGHT)
        return true;

    // Check if the player is trying to move into a wall
    if (worldMap[cellX][cellY] == 1)
        return true;

    // Check if the player is trying to move diagonally into a corner
    if (worldMap[cellX][static_cast<int>(playerY)] == 1 && worldMap[static_cast<int>(playerX)][cellY] == 1)
        return true;

    return false;
}

void castRays(SDL_Renderer* renderer, SDL_Texture* wallTexture, SDL_Texture* rainTexture, bool drawMap)
{
    SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
    SDL_RenderClear(renderer);

    const int MINIMAP_SCALE = 10;

    if (drawMap)
    {
        // Draw the map
        for (int y = 0; y < MAP_HEIGHT; ++y)
        {
            for (int x = 0; x < MAP_WIDTH; ++x)
            {
                int screenX = x * MINIMAP_SCALE;
                int screenY = y * MINIMAP_SCALE;
                SDL_Rect mapCellRect = { screenX, screenY, MINIMAP_SCALE, MINIMAP_SCALE };

                if (worldMap[x][y] == 1)
                {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderFillRect(renderer, &mapCellRect);
                }
                else
                {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    SDL_RenderDrawRect(renderer, &mapCellRect);
                }
            }
        }
    }

    // Raycasting logic

    int numRays = SCREEN_WIDTH;

    float rayAngle = wrapAngle(playerAngle - FOV / 2);

    float rayAngleIncrement = FOV / numRays;

    for (int rayIndex = 0; rayIndex < numRays; ++rayIndex)
    {
        float x = playerX;
        float y = playerY;
        float angle = wrapAngle(rayAngle + playerAngle);

        float distanceToWall = 0;
        bool hitWall = false;

        float eyeX = std::sin(angle);
        float eyeY = std::cos(angle);

        while (!hitWall && distanceToWall < 20.0f)
        {
            distanceToWall += 0.1f;

            int testX = static_cast<int>(x + eyeX * distanceToWall);
            int testY = static_cast<int>(y + eyeY * distanceToWall);

            if (testX < 0 || testX >= MAP_WIDTH || testY < 0 || testY >= MAP_HEIGHT)
            {
                hitWall = true;
                distanceToWall = 20.0f;
            }
            else if (worldMap[testX][testY] == 1)
            {
                hitWall = true;
            }
        }

        int ceilingHeight = SCREEN_HEIGHT / 2.0f - SCREEN_HEIGHT / distanceToWall;
        int floorHeight = SCREEN_HEIGHT - ceilingHeight;

        // Render the walls
        if (!isRaining)
        {
            SDL_Rect wallRect = { rayIndex, ceilingHeight, 1, floorHeight - ceilingHeight };
            SDL_RenderCopy(renderer, wallTexture, nullptr, &wallRect);
        }
        else
        {
            // Render raindrops if it's raining
            for (int y = ceilingHeight; y < floorHeight; y += 8)
            {
                SDL_Rect rainRect = { rayIndex, y, 1, 5 };
                SDL_RenderCopy(renderer, rainTexture, nullptr, &rainRect);
            }
        }

        rayAngle += rayAngleIncrement;
    }
}

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Raycasting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Texture* wallTexture = IMG_LoadTexture(renderer, "wall_texture.png");
    if (!wallTexture)
    {
        std::cerr << "Failed to load wall texture: " << IMG_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Texture* rainTexture = IMG_LoadTexture(renderer, "rain_texture.png");
    if (!rainTexture)
    {
        std::cerr << "Failed to load rain texture: " << IMG_GetError() << std::endl;
        SDL_DestroyTexture(wallTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    if (!parseMap("map.txt"))
    {
        std::cerr << "Failed to parse map" << std::endl;
        SDL_DestroyTexture(rainTexture);
        SDL_DestroyTexture(wallTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool quit = false;
    SDL_Event event;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    case SDLK_UP:
                        playerX += std::sin(playerAngle) * 0.1f;
                        playerY += std::cos(playerAngle) * 0.1f;
                        if (checkCollision(playerX, playerY))
                        {
                            playerX -= std::sin(playerAngle) * 0.1f;
                            playerY -= std::cos(playerAngle) * 0.1f;
                        }
                        break;
                    case SDLK_DOWN:
                        playerX -= std::sin(playerAngle) * 0.1f;
                        playerY -= std::cos(playerAngle) * 0.1f;
                        if (checkCollision(playerX, playerY))
                        {
                            playerX += std::sin(playerAngle) * 0.1f;
                            playerY += std::cos(playerAngle) * 0.1f;
                        }
                        break;
                    case SDLK_LEFT:
                        playerAngle -= 5.0f;
                        break;
                    case SDLK_RIGHT:
                        playerAngle += 5.0f;
                        break;
                    case SDLK_m:
                        drawMapEnabled = !drawMapEnabled;
                        break;
                    case SDLK_r:
                        isRaining = !isRaining;
                        break;
                }
            }
        }

        castRays(renderer, wallTexture, rainTexture, drawMapEnabled);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(rainTexture);
    SDL_DestroyTexture(wallTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
