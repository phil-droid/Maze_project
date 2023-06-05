			THE MAZE PROJECT

Introduction:
The goal of this project is to create a game in 3D using raycasting. The game will have basic features such as walls, sky, ground, weapons and players.

Team members:
PHIL COLLINS:The whole project would be carried out by myself.

Project Timeline:
Phase1:Project planning and  design:
During the first week the project requirements will be finalized, a project plan created and a final  design settled upon.

Phase2:Development
The actual game development will be undertaken in steps adding new features as the project progresses.

Phase3:Testing
Testing would be conducted to ensure proper functionality and to ensure all requirements are met.

Phase4:Deployment

Phase5:Product Landing Page

Technologies:
C++: C++ programming language is a versatile programming language. Using C++ you can create low end graphics too i.e. creating basic shapes and words with stylish fonts and adding colors to them can be done using c++.
Simple DirectMedia Layer (SDL2): SDL2 is a  cross-platform library designed to provide a hardware abstraction layer  for computer multimedia hardware components used  to write high-performance computer games.
Github:Github would be used as the version control to enable collaboration with other developers interested in the project and maintain a history of changes made to the code.


Challenge:
Provide an immersive game experience: The project aims to create a 3D game using raycasting techniques, allowing players to explore a maze like environment with walls, sky, ground, weapons and other interactive elements.
Showcase the capabilities of C++ and SDL2 for game development: The project ams to demonstrate the versatility of C++ and the capabilities of SDL2 library for creating high performance computer games.
What the game project would not solve:
Advanced AI and complex game mechanics: The project is not focused on advanced AI and game mechanics. The game would have basic features such as player movement , collision, detection and interaction with objects.
Realistic graphics and high-end visual effects: While the project  aims to create a visually appealing environment using raycasting techniques, it’s not focused on achieving realistic graphics or high end visual effects.

Risks:
Technical risks:
Bugs:-These are errors in the code that can cause the website to malfunction. Bugs can be costly and hard to fix and can damage the website’s hype and reputation.
Security Vulnerabilities:-These are weaknesses in the website’s code that can be exploited by attackers or hackers.The security vulnerabilities can lead to reputational damage, financial losses and data breaches.
Technical debt:-This is the cost  of additional  rework caused by choosing an easy solution instead of using a better approach that would take longer. Technical debt may lead to higher maintenance costs, performance problems and security vulnerabilities.

Non-Technical risks:
Lack of user adoption:-Incase the game interface is not user friendly, users might not adopt it resulting in low traffic and low adoption rates.
Software Changes:-If the game  does not keep up with the constant software changes and updates  it might become obsolete.

Safeguards and Alternatives:
Technical risks:
To  prevent bugs a rigorous code review process is employed. Potential bugs would also be detected using static analysis tools.
To secure the game, industry standard security practices would be employed.
To mitigate technical debt, a development process that emphasizes continuous integration and continuous deployment would be applied.

Non-Technical risks:
To mitigate the problem of user adoption, the game would have an easy-to-navigate design, using the machine's keyboard for navigation and game movements.
To keep up with the software changes the game  would need continuous updates to keep up with emerging trends and technologies.
To remain competitive, the site would need constant updates and improvements to reflect the current market conditions and requirements.




Infrastructure:
Branching and merging:
The github workflow would be followed for branching and merging into my repository.The workflow would involve creating a separate branch for each feature or bug fix and merging it back into the master branch once reviewing testing is done.
Deployment strategy:
The deployment process would involve continuous integration and continuous delivery (CI/CD)approach where the building, testing and deployment process is automated.
Testing tools:
A combination of unit tests, and integration tests  to ensure the application functions correctly  and that new changes do not introduce any regressions. C++ offers various unit testing frameworks like Google Test which can be used to write and execute tests.

Existing solutions:
Pac-Man: A classic arcade game where players control a character  navigating through a maze while collecting pallets and avoiding enemies.

Minimum Viable Product (MVP):
The Minimum Viable Product (MVP) for the maze game project will focus on delivering the core features and functionalities to provide an engaging and playable experience. The MVP will serve as a foundation upon which additional features can be built in future iterations. The primary objective of the MVP is to demonstrate the basic gameplay mechanics and showcase the immersive environment created using raycasting techniques.
The MVP will include the following key components:
Maze Generation: The game will generate randomized mazes with walls, corridors, and an exit point. The mazes can be designed with varying complexity levels to provide a challenging experience for players.
Player Movement: Players will be able to control a character within the maze using keyboard input or other appropriate input methods. The character movement will allow them to explore the maze, navigate through corridors, and avoid obstacles.
Raycasting Rendering: The game will utilize raycasting techniques to create a 3D-like visual representation of the maze environment. Walls, floors, and ceilings will be rendered, giving players a sense of depth and immersion.
Collision Detection: The player character will interact with the maze walls and objects using collision detection. This will prevent the character from walking through walls or other solid objects, ensuring a realistic and constrained movement within the maze.
Objective Completion: The objective of the game will be to reach the exit point of the maze. Once the player successfully reaches the exit, a victory condition will be triggered, indicating the completion of the level.
User Interface: The MVP will include a simple user interface displaying relevant information such as the player's current position, a mini-map showing the explored areas of the maze, and any additional necessary game information.

By focusing on these core features, the MVP will provide a playable maze game experience, allowing users to navigate through visually appealing maze environments, solve puzzles, and accomplish the primary objective of reaching the exit point. The MVP will serve as a solid foundation for further enhancements and iterations, allowing for the addition of more advanced gameplay mechanics, enemy interactions, power-ups, and other exciting features in future development phases.

Progress:
Achievement rating  on a scale of 1 to 10: 8.
This week, significant progress has been made in various areas of the project. The key milestones achieved include:
Completed the game planning and design phase, finalizing the project requirements, and settling on a final design.
Started the development phase and implemented the foundational components of the game, such as maze generation, player movement, and collision detection.
Integrated the SDL2 library successfully, enabling the creation of a graphical environment for the game.
Implemented a basic user interface to display relevant information and provide a visual representation of the game state.
Conducted initial testing to ensure the implemented features function correctly.
The following parts of the project are completed as planned:
Project planning and design phase, including finalizing requirements and creating a project plan.
Implementation of foundational components, such as maze generation and player movement.
Integration of the SDL2 library and creation of a graphical environment.
However, there are still aspects of the project that remain incomplete or require further work:
Additional features and gameplay mechanics, such as enemy interactions, power-ups, and level progression, are yet to be implemented.
Fine-tuning and optimization of the game mechanics and performance are ongoing tasks.
Extensive testing and bug fixing are required to ensure proper functionality and stability of the game.
Overall, the progress made this week has been substantial, with the completion of planned milestones. However, there are still remaining tasks to be addressed in the upcoming weeks to achieve the full vision and functionality of the maze game project.

Challenges:
The most difficult technical challenge encountered in the second week was implementing the raycasting algorithm to render the 3D perspective view of the maze. Raycasting involves casting virtual rays from the player's viewpoint to calculate the distance and height of walls, which are then projected onto the screen to create the illusion of depth. This algorithm is crucial for creating the immersive 3D experience in the game.
The implementation of raycasting required a deep understanding of trigonometry, vector math, and the principles of 3D projection. Calculating the intersections of the rays with the walls and performing the necessary calculations to determine the height and texture mapping of the walls proved to be complex and mathematically intensive. Additionally, optimizing the algorithm for performance was a challenge to ensure smooth and real-time rendering of the game.

To overcome this challenge, extensive research was conducted to understand the underlying concepts and mathematical principles behind raycasting. Various online resources, tutorials, and code examples were studied to gain insights into efficient raycasting techniques. Experimentation and iterative development were carried out to fine-tune the algorithm and address any performance bottlenecks.

The most difficult non-technical challenge encountered in the second week was managing time effectively and maintaining focus amidst competing priorities. Developing a game project requires juggling multiple tasks, including planning, design, development, testing, and documentation. It is essential to allocate time and resources efficiently to ensure progress in all areas while maintaining a high level of quality.

The non-technical challenge of time management became evident as the project moved into the development phase. Balancing the implementation of game features, testing, and documentation proved to be demanding. It was crucial to establish a structured schedule, set realistic goals, and prioritize tasks based on their importance and dependencies.

To address this challenge, a time management strategy was adopted, which included setting specific time blocks for different project activities. This allowed for focused work on development tasks while dedicating separate time slots for testing, documentation, and project planning. Additionally, regular progress checks and self-assessment were conducted to ensure adherence to the schedule and identify any areas where adjustments were required.

Maintaining motivation and discipline was also vital in overcoming this non-technical challenge. Creating a positive and conducive work environment, setting clear goals, and celebrating small milestones helped to stay motivated and committed to the project's progress.

Overall, effective time management and maintaining focus were crucial non-technical challenges in the second week, which required discipline, organization, and adaptability to overcome successfully.

