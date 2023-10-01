cmake_minimum_required(VERSION 3.5)
project(my_1)

# Set the C compiler to MinGW (assuming you have it installed and in your PATH)
set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)

# Set the source files for your project
set(SOURCES
    src/my_1.c
    # Add more source files if needed
)

# Find the necessary libraries
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

# Include directories for the libraries
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

# Create the executable
add_executable(${PROJECT_NAME}  ${SOURCES})

# Link the libraries to your executable
target_link_libraries(${PROJECT_NAME} OpenGL::GL GLUT::GLUT GLEW::GLEW)

# Set the output directory for the Windows executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Set the output executable name
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# Optionally, you can add compiler flags if needed
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

# Copy necessary DLLs to the output directory
file(COPY
    /usr/x86_64-w64-mingw32/bin/libssp-0.dll
    /usr/x86_64-w64-mingw32/bin/glew32.dll 
    /usr/x86_64-w64-mingw32/bin/libfreeglut.dll
    DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
    