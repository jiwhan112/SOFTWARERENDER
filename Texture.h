#pragma once

#include "stdafx.h"
#include "Vector.h"

//텍스처 파일 클래스

class Texture
{
public:
	Texture() : Buffer(NULL), width(0), height(0) {}
	~Texture() { if (Buffer != NULL) delete Buffer; }

	bool IsLoaded() { return (Buffer != NULL);  }

	bool LoadBMP(char* filename);
	ULONG GetPixel(int x, int y);
	//ULONG GetTexturePixel(float s, float t, const Triangle& tri);
	ULONG TextureSample(Vector2 TexCoord, float s, float t); // 텍스처좌표 반환
	int width;
	int height;		
	ULONG* Buffer;
};