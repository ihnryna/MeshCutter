#include "raylib.h"
#include "raymath.h"
#include "Plane.h"

//TODO: review
void DrawCutPlane(const Plane &cutPlane, float sizeX, float sizeZ, Color color) {
    Mesh planeMesh = GenMeshPlane(sizeX, sizeZ, 2, 2);
    UploadMesh(&planeMesh, false);

    Vector3 up = {0, 1, 0};
    Vector3 down = {0, -1, 0};

    Vector3 n = cutPlane._normal;
    n = Vector3Normalize(n);

    Vector3 axis = Vector3CrossProduct(up, n);
    float axisLen = Vector3Length(axis);

    Vector3 axisDown = Vector3CrossProduct(down, n);
    float axisLenDown = Vector3Length(axis);

    Matrix mat = MatrixIdentity();
    Matrix matDown = MatrixIdentity();

    if (axisLen > 0.0001f) {
        axis = Vector3Normalize(axis);
        float angle = acosf(Vector3DotProduct(up, n));
        mat = MatrixRotate(axis, angle);
    }

    if (axisLenDown > 0.0001f) {
        axisDown = Vector3Normalize(axisDown);
        float angle = acosf(Vector3DotProduct(down, n));
        matDown = MatrixRotate(axisDown, angle);
    }

    mat = MatrixMultiply(mat, MatrixTranslate(cutPlane._point.x, cutPlane._point.y, cutPlane._point.z));
    matDown = MatrixMultiply(matDown, MatrixTranslate(cutPlane._point.x, cutPlane._point.y, cutPlane._point.z));

    Material matDefault = LoadMaterialDefault();
    matDefault.maps[MATERIAL_MAP_DIFFUSE].color = color;
    DrawMesh(planeMesh, matDefault, mat);
    DrawMesh(planeMesh, matDefault, matDown);

    UnloadMaterial(matDefault);

    UnloadMesh(planeMesh);
}

int classifyVertex(const Vector3 &v, const Plane &p) {
    const float d = (v.x - p._point.x) * p._normal.x +
                    (v.y - p._point.y) * p._normal.y +
                    (v.z - p._point.z) * p._normal.z;

    if (d > 0.0001f) return 1;
    if (d < -0.0001f) return -1;
    return 0;
}
