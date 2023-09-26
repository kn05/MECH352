cmake_minimum_required(VERSION 3.5)
project(hw1)

# Find OpenGL package
find_package(OpenGL REQUIRED)

# Include directories for GLEW and GLUT
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/external/glew/include)  # Adjust the path to your GLEW headers
include_directories(${CMAKE_SOURCE_DIR}/external/glut)          # Adjust the path to your GLUT headers

# Source files for your project
set(SOURCES
    src/my_1.c  # Replace with your source files
)

# Link directories for GLEW and GLUT
link_directories(${CMAKE_SOURCE_DIR}/external/glew/lib)  # Adjust the path to your GLEW libraries
link_directories(${CMAKE_SOURCE_DIR}/external/glut)      # Adjust the path to your GLUT libraries

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link against GLEW, GLUT, and OpenGL
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
target_link_libraries(${PROJECT_NAME} GLEW)
target_link_libraries(${PROJECT_NAME} glut)
