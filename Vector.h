#pragma once
//Vector
#include "stdafx.h";
#include "Matrix.h"

struct IntPoint
{
public:
	int X;
	int Y;

public:
	IntPoint() : X(0), Y(0) {}
	IntPoint(int InX, int InY) : X(InX), Y(InY) {}

};


class Vector2
{
public:
	float X;
	float Y;

public:
	Vector2() :X(0), Y(0) {}
	Vector2(float inX, float inY) : X(inX), Y(inY) {}

	static float Dist(const Vector2&v1, const Vector2&v2); // 거리
	static float DistSquared(const Vector2&v1, const Vector2&v2);
	
	Vector2 operator-() const//-Vector
	{
		return Vector2(-X, -Y);
	}

	IntPoint ToIntPoint()
	{
		return IntPoint((int)(X), (int)(Y));
	}

	//Vector2 operator *(float scale) const;
	//Vector2 operator *(const Matrix2 Mat) const;
	bool Equals(const Vector2& V, float Tolerance = KINDA_SMALL_NUMBER) const;

	//사칙연산
		Vector2 operator+(const Vector2 &v) const
	{
		return Vector2(X + v.X, Y + v.Y);
	};
		Vector2 operator-(const Vector2 &v) const
	{
		return Vector2(X - v.X, Y - v.Y);
	};
		Vector2 operator*(const float Scalar) const
	{
			Vector2 result;
			result.X = X * Scalar;
			result.Y = Y * Scalar;
			return result;
	};
		Vector2 operator/(const float Scalar) const
	{
		return Vector2(X, Y) /Scalar;
	};

		Vector2 operator/(const Vector2 v) const
	{
		return Vector2(X / v.X, Y/v.Y);
	};

		Vector2 & operator+=(const Vector2 &v)
	{
		X += v.X;
		Y += v.Y;

		return *this;
	}
		Vector2 & operator-=(const Vector2 &v)
	{
		X -= v.X;
		Y -= v.Y;

		return *this;
	}
		Vector2 & operator*=(const Vector2 &v)
	{
		X *= v.X;
		Y *= v.Y;

		return *this;
	}

		Vector2 & operator*=(const float scalar)
	{
		X *= scalar;
		Y *= scalar;

		return *this;
	}
		Vector2 & operator/=(const Vector2 &v)
	{
		X /= v.X;
		Y /= v.Y;

		return *this;
	}
		Vector2 & operator/=(const float scalar)
	{
		X /= scalar;
		Y /= scalar;

		return *this;
	}
	
	float Dot(const Vector2&v)const //내적
	{
		return X * v.X + Y * v.Y;
	}

//	Vector2 operator+(const Vector2& V) const;
//	Vector2 operator-(const Vector2& V) const;

	Vector2 operator*(const Matrix2 &m)const // 행렬 곱
	{
		Vector2 result;
		result.X = X * m._11 + Y * m._12;
		result.Y = X * m._21 + Y * m._22;
		return result;
	}


	//FORCEINLINE	bool Equals(const Vector2& v, float Tolerance = KINDA_SMALL_NUMBER)const; // 동일
	//	float Dot(const Vector2&v)const; //내적
	//	float Cross(const Vector2& v)const; //외적

	//	void Normalize();
	
};


FORCEINLINE bool Vector2::Equals(const Vector2& V, float Tolerance) const
{
	return fabs(X - V.X) <= Tolerance && fabs(Y - V.Y) <= Tolerance;
}


struct Vector3
{
public:
	float X;
	float Y;
	float Z;

	Vector3() : X(0), Y(0), Z(0) {}
	Vector3(float InX, float InY, float InZ) : X(InX), Y(InY), Z(InZ) {}

	void SetPoint(float InX, float InY)
	{
		X = InX;
		Y = InY;
		Z = 1.0f;
	}

	void SetVector(float InX, float InY)
	{
		X = InX;
		Y = InY;
		Z = 0.0f;
	}

	float Dist()
	{
		return sqrtf(DistSquared());
	}

	float DistSquared()
	{
		return X * X + Y * Y;
	}

	Vector2 ToVector2()
	{
		Vector2 result(X, Y);
		return result;
	}

	IntPoint ToIntPoint()
	{
		return IntPoint(RoundToInt(X), RoundToInt(Y));
	}

	float Dot(const Vector3 v) const
	{
		return X * v.X + Y * v.Y + Z * v.Z;
	}

	// 연산
	/*FORCEINLINE Vector3 operator*(float scale) const
	{
		Vector3 result;
		result.X = X * scale;
		result.Y = Y * scale;
		result.Z = Z * scale;
		return result;
	}
	FORCEINLINE Vector3 operator+(const Vector3& V) const
	{
		Vector3 result;
		result.X = X + V.X;
		result.Y = Y + V.Y;
		result.Z = Z + V.Z;
		return result;
	}
	FORCEINLINE	Vector3 operator-(const Vector3& V) const
	{
		Vector3 result;
		result.X = X - V.X;
		result.Y = Y - V.Y;
		result.Z = Z - V.Z;
		return result;
	}

	FORCEINLINE	Vector3 operator *(const Matrix3 Mat) const
	{
		Vector3 result;
		result.X = X * Mat._11 + Y * Mat._12 + Z * Mat._13;
		result.Y = X * Mat._21 + Y * Mat._22 + Z * Mat._23;
		result.Z = X * Mat._31 + Y * Mat._32 + Z * Mat._33;
		return result;
	}*/

	Vector3 operator*(float scale) const;
	Vector3 operator+(const Vector3& V) const;
	Vector3 operator-(const Vector3& V) const;
	Vector3 operator *(const Matrix3 Mat) const;
};



