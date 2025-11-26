//
// Created by User on 26.11.2025.
//
#pragma  once
#include "raylib.h"

class Plane {
    public:
    Plane(const Vector3 pointOnPlane, const Vector3 normal):_point(pointOnPlane), _normal(normal) {};
    Vector3 _point;
    Vector3 _normal;
};

void DrawCutPlane(const Plane &cutPlane, float sizeX, float sizeZ, Color color);
int classifyVertex(const Vector3 &v, const Plane &p);
