
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

Matrix3 Matrix3::operator*(const Matrix3 Other) const
{
	Matrix3 mat3;
	mat3._11 = _11 * Other._11 + _12 * Other._21 + _13 * Other._31;
	mat3._12 = _11 * Other._12 + _12 * Other._22 + _13 * Other._32;
	mat3._13 = _11 * Other._13 + _12 * Other._23 + _13 * Other._33;
	mat3._21 = _21 * Other._11 + _22 * Other._21 + _23 * Other._31;
	mat3._22 = _21 * Other._12 + _22 * Other._22 + _23 * Other._32;
	mat3._23 = _21 * Other._13 + _22 * Other._23 + _23 * Other._33;
	mat3._31 = _31 * Other._11 + _32 * Other._21 + _33 * Other._31;
	mat3._32 = _31 * Other._12 + _32 * Other._22 + _33 * Other._32;
	mat3._33 = _31 * Other._13 + _32 * Other._23 + _33 * Other._33;


	return mat3;
}
