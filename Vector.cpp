
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

