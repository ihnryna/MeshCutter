cmake_minimum_required(VERSION 4.0)
project(MeshCutter)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libs/glm)
add_subdirectory(libs/raylib)
add_subdirectory(libs/assimp)

add_executable(MeshCutter src/main.cpp
        src/CameraUtilities.h)

target_link_libraries(MeshCutter
        PRIVATE glm
        PRIVATE raylib
        PRIVATE assimp
)
