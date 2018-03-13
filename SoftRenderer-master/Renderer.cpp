
#include "stdafx.h"
#include "SoftRenderer.h"
#include "GDIHelper.h"
#include "Renderer.h"

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
	for (int j = -Radius; j < Radius; j++)
	{
		for (int i = -Radius; i < Radius; i++)
		{
			if (i*i + j * j <= Radius* Radius)
				PutPixel(i, j);
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

	if()
	PutCircle(50);
	
	//640 480

	
	
	
	// Buffer Swap 
	BufferSwap();
}
