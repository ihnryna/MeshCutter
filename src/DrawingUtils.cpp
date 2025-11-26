#include "DrawingUtils.h"

void DrawWithColor(const Vector3 v, const Plane &cutPlane) {
    if (const int side = classifyVertex(v, cutPlane); side > 0) DrawSphere(v, 0.05f, RED);
    else if (side == 0) DrawSphere(v, 0.05f, YELLOW);
    else DrawSphere(v, 0.05f, BLUE);
}
