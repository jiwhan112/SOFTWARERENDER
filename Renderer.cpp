
#include "stdafx.h"
#include "SoftRenderer.h"
#include "GDIHelper.h"
#include "Renderer.h"
#include"Vector.h"
bool IsInRange(int x, int y);
void PutPixel(int x, int y);

bool IsInRange(int x, int y)
{
	return (abs(x) < (g_nClientWidth / 2)) && (abs(y) < (g_nClientHeight / 2));
}

void PutPixel(int x, int y)
{
	if (!IsInRange(x, y)) return;

	ULONG* dest = (ULONG*)g_pBits;
	DWORD offset = g_nClientWidth * g_nClientHeight / 2 + g_nClientWidth / 2 + x + g_nClientWidth * -y;
	*(dest + offset) = g_CurrentColor;
}
void PutPixel(Vector2 vec)
{
	vec.X = (int)vec.X;
		vec.Y = (int)vec.Y;
	if (!IsInRange(vec.X, vec.Y)) return;
	
	ULONG* dest = (ULONG*)g_pBits;
	DWORD offset = g_nClientWidth * g_nClientHeight / 2 + g_nClientWidth / 2 + vec.X + g_nClientWidth * -vec.Y;
	*(dest + offset) = g_CurrentColor;
}

void PutCircle(int Radius)
{
	Vector2 Center(0,0);
	for (int j = -Radius; j < Radius; j++)
	{
		for (int i = -Radius; i < Radius; i++)
		{
			Vector2 CurrentPos(i, j);
			if (Vector2::DistSquared(Center, CurrentPos) <= Radius * Radius)
			{ 
				PutPixel(CurrentPos);
			}
		}
	}
	
}



void PutCircle(int Radius,float ScaleA,float ScaleB)
{
	Vector2 Center(0, 0);
	//Matrix2 mMat(0,1,1,0); // 밀기 변환
	Matrix2 mMat(0,0,0,0); 
	mMat.SetScale(ScaleA,ScaleB);
	for (int j = -Radius; j < Radius; j++)
	{
		for (int i = -Radius; i < Radius; i++)
		{
			Vector2 CurrentPos(i, j);
			Vector2 OutPos =  CurrentPos * mMat;
			if (Vector2::DistSquared(Center, CurrentPos) <=Radius * Radius)
			{
				PutPixel(OutPos);
			}
		}
	}

}

void UpdateFrame(void)
{
	// Buffer Clear
	SetColor(32, 128, 255);
	Clear();

	// Draw
	SetColor(255, 0, 0);

	//640 480

	//PutCircle(50,1,1);
	
	int Length = 100;
	Matrix2 mat;
	mat.SetIdentity();
	static float angle = 0.0f;
	angle -= 0.1f;
	mat.SetRotaion(angle);
	for (int i = 0; i < Length; i++)
	{
		for (int j = 0; j < Length; j++)
		{
			if (i == j)
			{
				Vector2 outPos(i, j);
				Vector2 newPos = outPos * mat;
				PutPixel(newPos);
			}
		}
	}

	// Buffer Swap 
	BufferSwap();
}
