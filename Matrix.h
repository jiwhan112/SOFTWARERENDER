#pragma once
#include "stdafx.h";

class Matrix2
{
	float PIE = 3.14f;
public:
	float _11, _12;
	float _21, _22;
	Matrix2() { _11 = 0; _12 = 0; _21 = 0; _22 = 0; };
	Matrix2(float m11, float m12, float m21, float m22)
	{
		_11 = m11;
		_12 = m12;
		_21 = m21;
		_22 = m22;
	}
	~Matrix2() {}

	void SetScale(float a, float b)
	{
		SetIdentity();
		_11 = a;
		//	_12 = 0.0f;
		//	_21 = 0.0f;
		_22 = b;
	}
	void SetIdentity()
	{
		_11 = 1.0f;
		_12 = 0.0f;

		_21 = 0.0f;
		_22 = 1.0f;
	};
	void SetRotaion(float degree)
	{

		float radion = Deg2Rad(degree);
		_11 = cosf(radion);
		_12 = -sinf(radion);
		_21 = sinf(radion);
		_22 = cosf(radion);
	}



#pragma region  ������



	void operator+(const Matrix2& m)
	{
		_11 += m._11;
		_12 += m._12;
		_21 += m._21;
		_22 += m._22;
	}
	void operator-(const Matrix2& m)
	{
		_11 -= m._11;
		_12 -= m._12;
		_21 -= m._21;
		_22 -= m._22;
	}


	Matrix2 operator+(const Matrix2 &m) const
	{
		return Matrix2(_11 + m._11, _12 + m._12, _21 + m._21, _22 + m._22);
	};
	Matrix2 operator-(const Matrix2 &m) const
	{
		return Matrix2(_11 - m._11, _12 - m._12, _21 - m._21, _22 - m._22);
	}


	Matrix2 operator*(const Matrix2& m) const
	{
		Matrix2 Temp;
		Temp._11 = _11 * m._11 + _12 * m._21;
		Temp._12 = _11 * m._12 + _12 * m._22;
		Temp._21 = _21 * m._11 + _22 * m._21;
		Temp._22 = _21 * m._12 + _22 * m._22;

		return Temp;
	}

	void operator*=(const Matrix2 &m)
	{
		Matrix2 Temp;
		Temp._11 = _11 * m._11 + _12 * m._21;
		Temp._12 = _11 * m._12 + _12 * m._22;
		Temp._21 = _21 * m._11 + _22 * m._21;
		Temp._22 = _21 * m._12 + _22 * m._22;

		_11 = Temp._11;
		_12 = Temp._12;
		_21 = Temp._21;
		_22 = Temp._22;

	};

	Matrix2 operator*(const float scalar) const
	{
		Matrix2 Temp;
		Temp._11 = _11 * scalar;
		Temp._12 = _12 * scalar;
		Temp._21 = _21 * scalar;
		Temp._22 = _22 * scalar;
		return Temp;
	}

	void operator*=(const float scalar)
	{
		_11 *= scalar;
		_12 *= scalar;
		_21 *= scalar;
		_22 *= scalar;
	};

	friend Matrix2 operator*(const float scalar, const Matrix2 &m);

#pragma endregion

	void TransPose() // ��ġ���
	{
		float temp;

		temp = _21;
		_21 = _12;
		_12 = temp;
	};

	void Inverse()
	{
		float Det = _11 * _22 - _12 * _21;
		float InvDet = 1.0f / Det;

		float temp_11 = _11;

		_11 = _22 * InvDet;
		_12 = -_12 * InvDet;
		_21 = -_21 * InvDet;
		_22 = temp_11 * InvDet;
	};

};