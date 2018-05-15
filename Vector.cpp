
#include "stdafx.h"
#include "Vector.h"
 float Vector2::Dist(const Vector2&v1, const Vector2&v2)
{
	return sqrtf(Vector2::DistSquared(v1, v2));
}
float Vector2::DistSquared(const Vector2&v1, const Vector2&v2)
{
	return (v2.X - v1.X) * (v2.X - v1.X) + (v2.Y - v1.Y) * (v2.Y - v1.Y);
}

//Vector2 Vector2::operator+(const Vector2 & V) const
//{
//	Vector2 result;
//	result.X = X + V.X;
//	result.Y = Y + V.Y;
//	return result;
//}
//
//Vector2 Vector2::operator-(const Vector2 & V) const
//{
//	Vector2 result;
//	result.X = X - V.X;
//	result.Y = Y - V.Y;
//	return result;
//}





Vector3 Vector3::operator*(float scale) const
{
	Vector3 result;
	result.X = X * scale;
	result.Y = Y * scale;
	result.Z = Z * scale;
	return result;
}

Vector3 Vector3::operator-(const Vector3& V) const
{
	Vector3 result;
	result.X = X - V.X;
	result.Y = Y - V.Y;
	result.Z = Z - V.Z;
	return result;
}


Vector3 Vector3::operator+(const Vector3& V) const
{
	Vector3 result;
	result.X = X + V.X;
	result.Y = Y + V.Y;
	result.Z = Z + V.Z;
	return result;
}

Vector3 Vector3::operator*(Matrix3 Mat) const
{
	Vector3 result;
	result.X = X * Mat._11 + Y * Mat._12 + Z * Mat._13;
	result.Y = X * Mat._21 + Y * Mat._22 + Z * Mat._23;
	result.Z = X * Mat._31 + Y * Mat._32 + Z * Mat._33;
	return result;
}

