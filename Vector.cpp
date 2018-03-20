
#include "stdafx.h"
#include "Vector.h"
float Vector2::Dist(const Vector2&v1, const Vector2&v2)
{
	return sqrtf(DistSquared(v1, v2));
}
float Vector2::DistSquared(const Vector2&v1, const Vector2&v2)
{
	return (v2.X - v1.X)*(v2.X - v1.X) + (v2.Y - v1.Y)*(v2.Y - v1.Y);
}

Vector2 Vector2::operator*(const Matrix2 & m) const
{
	Vector2 Temp;
	Temp.X = X * m._11 + Y * m._21;
	Temp.Y = X * m._12 + Y * m._22;
	return Temp;
}

