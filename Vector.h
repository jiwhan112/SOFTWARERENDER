#pragma once
#include "stdafx.h";
#include "Matrix.h"
#define PIE 3.141592f


#pragma region Point
struct IntPoint
{
public:
	int X;
	int Y;

public:
	IntPoint() : X(0), Y(0) {}
	IntPoint(int InX, int InY) : X(InX), Y(InY) {}

};
#pragma endregion

#pragma region Vector2
struct Vector2
{
public:
	float X;
	float Y;

public:
	Vector2() :X(0), Y(0) {}
	Vector2(float inX, float inY) { X = inX; Y = inY; }
	static float Dist(const Vector2&v1, const Vector2&v2); // 벡터2개 거리구하기
	static float DistSquared(const Vector2&v1, const Vector2&v2);
	
	Vector2 operator-(void) const//-Vector
	{
		return Vector2(-X, -Y);
	}

#pragma region 벡터연산


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
#pragma endregion


	 Vector2 operator*(const Matrix2 &m)const; // 행렬 곱

	 float Dot(const Vector2&v)const //내적
	 {
		 return X * v.X + Y * v.Y;
	 }

	FORCEINLINE	bool Equals(const Vector2& v, float Tolerance = KINDA_SMALL_NUMBR)const; // 동일
	
	FORCEINLINE	float Cross(const Vector2& v)const; //외적 2차원에서는 이론상으로 가능

	FORCEINLINE	void Normalize(); //노말
	
};

#pragma endregion

#pragma region Vector3

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

	FORCEINLINE	Vector3 operator+(const Vector3 vec3) const
	{
		return Vector3(X + vec3.X, Y + vec3.Y, Z + vec3.Z);
	};
	FORCEINLINE	Vector3 operator-(const Vector3 vec3) const
	{
		return Vector3(X - vec3.X, Y - vec3.Y,Z-vec3.Z);
	};
	FORCEINLINE	Vector3 operator*(const Vector3 vec3) const
	{
		return Vector3(X * vec3.X, Y * vec3.Y, Z * vec3.Z);
	};
	FORCEINLINE	Vector3 operator*(const float Scalar) const
	{
		return Vector3(X * Scalar, Y * Scalar, Z * Scalar);
	};
	

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

	void SetPoint(float InX, float InY) // Point
	{
		X = InX;
		Y = InY;
		Z = 1.0f;
	}

	void SetVector(float InX, float InY) // Vector
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

	Vector2 TOVector2()
	{
		return Vector2(X, Y);
	}

	//int로 반환
	IntPoint ToIntPoint()
	{
		return IntPoint(RoundToInt(X), RoundToInt(Y));
	}

	float DOT(const Vector3& v) const;
	
	Vector3 operator *(const Matrix3 Mat) const;

};
#pragma endregion






