cmake_minimum_required(VERSION 4.0)
project(MeshCutter)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libs/glm)
add_subdirectory(libs/raylib)

add_executable(MeshCutter src/main.cpp
        src/DrawingUtils.cpp
        src/CameraUtilities.h
        src/Plane.cpp
)

target_link_libraries(MeshCutter
        PRIVATE glm
        PRIVATE raylib
)

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})