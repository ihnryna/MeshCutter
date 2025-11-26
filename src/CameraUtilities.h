//
// Created by User on 13.11.2025.
//
#pragma once
#define MY_CAMERA_MOVE_SPEED 5.4f
#include "rcamera.h"

inline void UpdateCameraPressAndDrag(Camera *camera, const int camera_mode) {
    const float cameraMoveSpeed = MY_CAMERA_MOVE_SPEED*GetFrameTime();

    if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)) {
        UpdateCamera(camera, camera_mode);
    } else {
        if (IsKeyDown(KEY_W)) CameraMoveForward(camera, cameraMoveSpeed, true);
        if (IsKeyDown(KEY_A)) CameraMoveRight(camera, -cameraMoveSpeed, true);
        if (IsKeyDown(KEY_S)) CameraMoveForward(camera, -cameraMoveSpeed, true);
        if (IsKeyDown(KEY_D)) CameraMoveRight(camera, cameraMoveSpeed, true);
    }
    if (IsKeyDown(KEY_SPACE)) CameraMoveUp(camera, cameraMoveSpeed);
    if (IsKeyDown(KEY_LEFT_CONTROL)) CameraMoveUp(camera, -cameraMoveSpeed);
}