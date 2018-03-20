#pragma once
#include "stdafx.h";
#include "Matrix.h"
#define PIE 3.141592f
struct Vector2
{
public:
	float X;
	float Y;

public:
	Vector2() :X(0), Y(0) {}
	Vector2(float inX, float inY) { X = inX; Y = inY; }
	static float Dist(const Vector2&v1, const Vector2&v2);
	static float DistSquared(const Vector2&v1, const Vector2&v2);

	Vector2 operator *(const Matrix2 &m)const;
};


