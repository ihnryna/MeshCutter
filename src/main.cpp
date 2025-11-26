#include <cmath>
#include <iostream>
#include "raylib.h"
#include "CameraUtilities.h"
#include "raymath.h"
#include "Plane.h"
#include "DrawingUtils.h"

int main() {
    constexpr int screenWidth = 1920;
    constexpr int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "mesh cutting project");

    Camera camera = {Vector3(5, 5, 5), Vector3(0, 0, 0), Vector3(0, 1, 0), 45.f, CAMERA_PERSPECTIVE};

    const Model model = LoadModel(R"(D:\CLionProjects\MeshCutter\assets\barrel.glb)");


    //TODO: refactor1 start
    const Mesh &oldMesh = model.meshes[0];

    Mesh newMesh = {};
    newMesh.vertexCount = oldMesh.vertexCount;
    newMesh.triangleCount = oldMesh.triangleCount;

    newMesh.vertices = new float[oldMesh.vertexCount * 3];
    newMesh.texcoords = new float[oldMesh.vertexCount * 2];
    newMesh.indices = new unsigned short[oldMesh.triangleCount * 3];

    memcpy(newMesh.vertices, oldMesh.vertices, sizeof(float) * oldMesh.vertexCount * 3);
    memcpy(newMesh.texcoords, oldMesh.texcoords, sizeof(float) * oldMesh.vertexCount * 2);
    memcpy(newMesh.indices, oldMesh.indices, sizeof(unsigned short) * oldMesh.triangleCount * 3);

    UploadMesh(&newMesh, true);
    model.meshes[0] = newMesh;

    Plane cutPlane = {{0, 0.5f, 0}, {0, 1, 0}};
    constexpr float angle = -PI / 4; // PI rad = 180 grad
    cutPlane._normal = {0, cosf(angle), sinf(angle)};

    //SetTargetFPS(60);
    //TODO: refactor1 end

    while (!WindowShouldClose()) {
        UpdateCameraPressAndDrag(&camera, CAMERA_FIRST_PERSON);
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawGrid(20, 15.f);
        DrawModel(model, {0, 0, 0}, 1.0f,WHITE);
        for (int i = 0; i < newMesh.vertexCount; i++) {
            const Vector3 vertex = {newMesh.vertices[i * 3], newMesh.vertices[i * 3 + 1], newMesh.vertices[i * 3 + 2]};
            DrawWithColor(vertex, cutPlane);
        }
        DrawCutPlane(cutPlane, 10.0f, 10.0f, {0, 158, 47, 100});

        EndMode3D();

        EndDrawing();
    }

    CloseWindow();
}
