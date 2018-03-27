
#include "stdafx.h"
#include "Vector.h"
FORCEINLINE float Vector2::Dist(const Vector2&v1, const Vector2&v2)
{
	return sqrtf(DistSquared(v1, v2));
}
FORCEINLINE float Vector2::DistSquared(const Vector2&v1, const Vector2&v2)
{
	return (v2.X - v1.X)*(v2.X - v1.X) + (v2.Y - v1.Y)*(v2.Y - v1.Y);
}

FORCEINLINE Vector2 Vector2::operator*(const Matrix2 & m) const
{
	Vector2 Temp;
	Temp.X = X * m._11 + Y * m._21;
	Temp.Y = X * m._12 + Y * m._22;
	return Temp;
}

FORCEINLINE bool Vector2::Equals(const Vector2 & v, float Tolerance) const
{
	return fabs(X - v.X) <= Tolerance && fabs(Y - v.Y) <= Tolerance;
}

FORCEINLINE float Vector2::Dot(const Vector2 & v) const
{
	return X * v.X + Y * v.Y;
}

FORCEINLINE float Vector2::Cross(const Vector2 & v) const
{
	
	return X * v.X + Y * v.Y;
}



FORCEINLINE void Vector2::Normalize()
{
	float invLength = 1/sqrt(X*X + Y * Y);

	X *= invLength;
	Y *= invLength;
}



