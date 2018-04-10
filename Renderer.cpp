
#include "stdafx.h"
#include "SoftRenderer.h"
#include "GDIHelper.h"
#include "Renderer.h"
#include"Vector.h"

bool IsInRange(int x, int y);
void PutPixel(int x, int y);

void PutCircle(int Radius, float ScaleA, float ScaleB);
void PutCircle(int Radius);
void DrawLine(Vector3 Pt1, Vector3 Pt2);


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

Vector3 Pt1, Pt2;

bool bUpdateInit = false;

void UpdateFrame(void)
{
	// Buffer Clear
	SetColor(32, 128, 255);
	Clear();

	// Draw
	SetColor(255, 0, 0);

	//640 480
#pragma region Circle
//	PutCircle(50, 1, 1);
#pragma endregion

#pragma region DRAWLINE AND MOVE CIRCLE

	/*int Length = 100;
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
	}*/

	if (bUpdateInit == false)
	{
		bUpdateInit = true;
		Pt1.SetPoint(0, 0);
		Pt2.SetPoint(100, 100);
	}
	
	
	DrawLine(Pt1, Pt2);
	//PutPixel(x, y);
	Matrix2 mat;
	mat.SetRotaion(1);
	if (GetAsyncKeyState(VK_LEFT))
	{
		// 이동
		/*Pt1 += Vector3(-1, 0, 0);
		Pt2 += Vector3(-1, 0, 0);
*/
		Pt1 *= mat;
		Pt2 *= mat;


	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		// 회전
		Pt1 += Vector3(1, 0, 0);
		Pt2 += Vector3(1, 0, 0);

	}
	if (GetAsyncKeyState(VK_UP))
	{

	}
	if (GetAsyncKeyState(VK_DOWN))
	{

	}

	// Buffer Swap 
	BufferSwap();
}


// Custom Draw


void PutCircle(int Radius)
{
	Vector2 Center(0, 0);
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



void PutCircle(int Radius, float ScaleA, float ScaleB)
{
	Vector2 Center(0, 0);
	//Matrix2 mMat(0,1,1,0); // 밀기 변환
	Matrix2 mMat(0, 0, 0, 0);
	mMat.SetScale(ScaleA, ScaleB);
	for (int j = -Radius; j < Radius; j++)
	{
		for (int i = -Radius; i < Radius; i++)
		{
			Vector2 CurrentPos(i, j);
			Vector2 OutPos = CurrentPos * mMat;
			if (Vector2::DistSquared(Center, CurrentPos) <= Radius * Radius)
			{
				PutPixel(OutPos);
			}
		}
	}
}


bool bOnTime = false;

void DrawLine(Vector3 Start , Vector3 End)
{
	
	Vector3 DrawVector = Vector3(End.X - Start.X, End.Y - Start.Y, End.Z - Start.Z);
	
	

	float m = float((End.Y - Start.Y) / (End.X - Start.X));
	float y = Start.Y;
	for (int x = Start.X; x < End.X; x++)
	{
	
		y += m;
			PutPixel(x, y);
		
	}


	if (!bOnTime) {
		cout << "Vector: " << Start.X << " " << End.X << " M: " << m;
		bOnTime = true;
	}
	


}