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
	
	Vector2 operator-(void) const//-Vector
	{
		return Vector2(-X, -Y);
	}

	//사칙연산
	FORCEINLINE	Vector2 operator+(const Vector2 &v) const
	{
		return Vector2(X + v.X, Y + v.Y);
	};
	FORCEINLINE	Vector2 operator-(const Vector2 &v) const
	{
		return Vector2(X - v.X, Y - v.Y);
	};
	FORCEINLINE	Vector2 operator*(const float Scalar) const
	{
		return Vector2(X, Y) *Scalar;
	};
	FORCEINLINE	Vector2 operator/(const float Scalar) const
	{
		return Vector2(X, Y) /Scalar;
	};

	FORCEINLINE	Vector2 operator*(const Vector2 v) const
	{
		return Vector2(X*v.X, Y*v.Y);
	};
	FORCEINLINE	Vector2 operator/(const Vector2 v) const
	{
		return Vector2(X / v.X, Y*v.Y);
	};


	
	FORCEINLINE	Vector2 & operator+=(const Vector2 &v)
	{
		X += v.X;
		Y += v.Y;

		return *this;
	}
	FORCEINLINE	Vector2 & operator-=(const Vector2 &v)
	{
		X -= v.X;
		Y -= v.Y;

		return *this;
	}
	FORCEINLINE	Vector2 & operator*=(const Vector2 &v)
	{
		X *= v.X;
		Y *= v.Y;

		return *this;
	}

	FORCEINLINE	Vector2 & operator*=(const float scalar)
	{
		X *= scalar;
		Y *= scalar;

		return *this;
	}
	FORCEINLINE	Vector2 & operator/=(const Vector2 &v)
	{
		X /= v.X;
		Y /= v.Y;

		return *this;
	}
	FORCEINLINE Vector2 & operator/=(const float scalar)
	{
		X /= scalar;
		Y /= scalar;

		return *this;
	}
	

	 Vector2 operator*(const Matrix2 &m)const; // 행렬 곱
	FORCEINLINE	bool Equals(const Vector2& v, float Tolerance = KINDA_SMALL_NUMBR)const; // 동일
	FORCEINLINE	float Dot(const Vector2&v)const; //내적
	FORCEINLINE	float Cross(const Vector2& v)const; //외적

	FORCEINLINE	void Normalize();
	
};


struct Vector3
{
public:
	float X;
	float Y;
	float Z;
	Vector3(float x, float y, float z) {
		X = x, Y = y, Z = z;
	}
	Vector3() {
		X = Y = Z = 0;
	}
	
	Vector3 & operator+=(const Vector3 &v)
	{
		X += v.X;
		Y += v.Y;
		Z += v.Z;
		return *this;
	}

	Vector3 & operator*=(const Matrix2 &m)
	{
		X = X * m._11 + X * m._21;
		Y = Y * m._12 + Y * m._22;

		
		return *this;
	}
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
};

