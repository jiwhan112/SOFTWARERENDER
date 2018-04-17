#pragma once
#include "Vector.h"
#include "stdafx.h"
#include "Renderer.h"
struct Vertex
{

public :
	Vertex(){}
	Vector3 pos;
	ULONG color;

	void SetPos(Vector3 _pos) {
		pos = _pos;
	}
	void SetPos(Vector2 _pos) {
		pos.X = _pos.X;
		pos.Y = _pos.Y;
		pos.Z = 1;
	}
	void SetPos(float x,float y, float z =1.0f) {
		pos.X = x;
		pos.Y = y;
		pos.Z = z;
	}

};

struct Triangle
{
public:
	Triangle() {}
	Triangle(Vertex a, Vertex b, Vertex c) {
		vertics[0] = a, vertics[0] = b, vertics[0] = c;
	}
	Vertex vertics[3];
	Matrix3 TMat, RMat, SMat; // 변환용

	Matrix3 GetMaterix()
	{
		return  TMat * RMat*SMat;
	}


	Triangle * operator * (const Matrix3& mat) 
	{
		vertics[0].pos = vertics[0].pos * mat;
		vertics[1].pos = vertics[1].pos * mat;
		vertics[2].pos = vertics[2].pos * mat;

		return this;
	}

	Triangle * operator = (const Triangle* tri)
	{
		vertics[0] = tri->vertics[0];
		vertics[1] = tri->vertics[1];
		vertics[2] = tri->vertics[2];

		return this;
	}


	vector<Vector2>* DrawInTriangle() // 현재 저장된 3개의 점을 이용해 삼각형 판단
	{
		float xMin, yMin;
		float xMax, yMax;
		xMin = yMin = INFINITY;
		xMax = yMax = -INFINITY;

		Vertex v1 = vertics[0];
		Vertex v2 = vertics[1];
		Vertex v3 = vertics[2];

		if (v1.pos.X < xMin) xMin = v1.pos.X;
		if (v2.pos.X < xMin) xMin = v2.pos.X;
		if (v3.pos.X < xMin) xMin = v3.pos.X;
		if (v1.pos.X > xMax) xMax = v1.pos.X;
		if (v2.pos.X > xMax) xMax = v2.pos.X;
		if (v3.pos.X > xMax) xMax = v3.pos.X;
		if (v1.pos.Y < yMin) yMin = v1.pos.Y;
		if (v2.pos.Y < yMin) yMin = v2.pos.Y;
		if (v3.pos.Y < yMin) yMin = v3.pos.Y;
		if (v1.pos.Y > yMax) yMax = v1.pos.Y;
		if (v2.pos.Y > yMax) yMax = v2.pos.Y;
		if (v3.pos.Y > yMax) yMax = v3.pos.Y;

		Vector2 u = (v2.pos - v1.pos).TOVector2();
		Vector2 v = (v3.pos - v1.pos).TOVector2();

		float dotUU = u.Dot(u);
		float dotUV = u.Dot(v);
		float dotVV = v.Dot(v);
		float invDenom = 1.0f / (dotUU * dotVV - dotUV * dotUV);

		vector<Vector2>* VecVector2 = new vector<Vector2>();
		// 삼각형 판단
		for (int y = RoundToInt(yMin); y < RoundToInt(yMax); y++)
		{
			for (int x = RoundToInt(xMin); x < RoundToInt(xMax); x++)
			{
				Vector2 w = (Vector3((float)x, (float)y, 0.0f) - v1.pos).TOVector2();
				float dotUW = u.Dot(w);
				float dotVW = v.Dot(w);
				float outS = (dotVV * dotUW - dotUV * dotVW) * invDenom;
				float outT = (dotUU * dotVW - dotUV * dotUW) * invDenom;
				if (outS < 0.0f) continue;
				if (outT < 0.0f) continue;
				if (outS + outT > 1.0f) continue;
				VecVector2->push_back(w);
			}
		}
		return VecVector2;
	}

	
};

