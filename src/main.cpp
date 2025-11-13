#include <iostream>
#include "raylib.h"
#include "CameraUtilities.h"

int main() {
    constexpr int screenWidth = 1920;
    constexpr int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "mesh cutting project");

    Camera camera = {Vector3(50, 50, 50), Vector3(0, 0, 0), Vector3(0, 1, 0), 45.f, CAMERA_PERSPECTIVE};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateCameraPressAndDrag(&camera, CAMERA_FIRST_PERSON);

        BeginDrawing();

        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        DrawGrid(20, 15.f);
        EndMode3D();

        EndDrawing();
    }

    CloseWindow();
}
