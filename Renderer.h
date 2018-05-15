#pragma once

#include "Mesh.h"
#include  "Triangle.h"

void InitFrame(void); //
void UpdateFrame(void); //
bool IsInRange(int x, int y); //���� �Ǵ�
void PutPixel(IntPoint pt); // �׷��ֱ�
void DrawCall(Mesh * MeshData);

V2F_CUSTOM VertexShader(APPDATA_CUSTOM in);
ULONG FragmentShader(V2F_CUSTOM in, float s, float t);