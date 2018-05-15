#pragma once

#include "Mesh.h"
#include  "Triangle.h"

void InitFrame(void); //
void UpdateFrame(void); //
bool IsInRange(int x, int y); //범위 판단
void PutPixel(IntPoint pt); // 그려주기
void DrawCall(Mesh * MeshData);

V2F_CUSTOM VertexShader(APPDATA_CUSTOM in);
ULONG FragmentShader(V2F_CUSTOM in, float s, float t);