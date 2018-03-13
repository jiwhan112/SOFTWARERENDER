
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
void PutCircle(int Radius)
{
	Vector2 Center(0,0);
	for (int j = -Radius; j < Radius; j++)
	{
		for (int i = -Radius; i < Radius; i++)
		{
			Vector2 CurrentPos(i, j);
			if (Vector2::DistSquared(Center,CurrentPos) <= Radius * Radius) 
			{
				PutPixel(i, j);
			}
		}
	}
	
}

int currentRed = 0;
void UpdateFrame(void)
{
	// Buffer Clear
	SetColor(32, 128, 255);
	Clear();

	// Draw
	if (currentRed >= 255)currentRed = 0;
	else
	currentRed+=1;
	SetColor(currentRed, 0, 0);

	PutCircle(radius);
	
	//640 480

	// Buffer Swap 
	BufferSwap();
}
