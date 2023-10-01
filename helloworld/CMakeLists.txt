cmake_minimum_required(VERSION 3.5)
project(helloworld)

# Adjust the path to your GLUT headers

# Source files for your project
set(SOURCES
    src/my_1.c  # Replace with your source files
)

# Link directories for GLEW and GLUT
     # Adjust the path to your GLUT libraries

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link against GLEW, GLUT, and OpenGL
