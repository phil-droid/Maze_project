# Use a base image with SDL and development libraries
FROM ubuntu:latest

# Install necessary dependencies
RUN apt-get update && \
    apt-get install -y libsdl2-dev libsdl2-image-dev

# Set the working directory inside the container
WORKDIR /Maze_project

# Copy the program files to the container
COPY . /Maze_project

# Build the program
RUN g++ -o raycasting main.cpp -lSDL2 -lSDL2_image -lm

# Set the command to run the program when the container starts
CMD ["./raycasting"]
