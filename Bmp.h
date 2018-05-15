#pragma once

#include "stdafx.h"
//BMP ÆÄÀÏ ¿ÀÇÂ ¹× ÇÈ¼¿À» ÀÐ¾î¿È

ULONG* OpenBMP(char *filename, int *pwidth, int *pheight);
ULONG GetPixel(int x, int width, int y, ULONG* bmp);