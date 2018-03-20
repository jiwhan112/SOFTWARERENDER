
#include "stdafx.h"
#include "Matrix.h"


Matrix2 operator*(const float scalar, Matrix2 &m)
{
	Matrix2 temp;

	temp._11 = m._11 * scalar;
	temp._12 = m._12 * scalar;

	temp._21 = m._21 * scalar;
	temp._22 = m._22 * scalar;

	return temp;
}