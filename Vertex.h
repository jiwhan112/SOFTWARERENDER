#pragma once

// Vertex������ ���� ����.

#include  "stdafx.h"
#include "Vector.h"

class Vertex
{
public:
	Vertex() {}
	~Vertex() {}
	Vertex(Vector3 v) {
		mPos = v; }
	Vector3 mPos;
	ULONG mColor;
	Vector2 mUv;
};

