cmake_minimum_required(VERSION 3.5)
project(hw1)

# Set the source files for your project
set(SOURCES
    src/main.cpp
    # Add more source files if needed
)

# Define an executable target for Linux


# Define an executable target for Windows


# Find the necessary libraries
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

# Include directories for the libraries
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

# Link the libraries to the Linux executable


# Conditionally copy necessary DLLs to the Windows executable
if(WIN32)
    add_executable(${PROJECT_NAME}_windows ${SOURCES})
    target_link_libraries(${PROJECT_NAME}_windows OpenGL::GL GLUT::GLUT GLEW::GLEW)
    file(COPY
        /usr/x86_64-w64-mingw32/bin/libssp-0.dll
        /usr/x86_64-w64-mingw32/bin/glew32.dll 
        /usr/x86_64-w64-mingw32/bin/libfreeglut.dll
        DESTINATION ${CMAKE_BINARY_DIR}/bin/windows
    )
    message("Building for Windows")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/windows")
    set_target_properties(${PROJECT_NAME}_windows PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/windows"
    )
else()
    add_executable(${PROJECT_NAME}_linux ${SOURCES})
    target_link_libraries(${PROJECT_NAME}_linux OpenGL::GL GLUT::GLUT GLEW::GLEW)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/linux")
    message("Building for a non-Windows platform")
    set_target_properties(${PROJECT_NAME}_linux PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/linux"
    )
endif()
