
#include "stdafx.h"
#include "SoftRenderer.h"
#include "GDIHelper.h"
#include "Renderer.h"
#include "Triangle.h"
#include "Texture.h"

void DrawFillBox(int x1, int y1, int x2, int y2);

bool IsInRange(int x, int y)
{
	return (abs(x) < (g_nClientWidth / 2)) && (abs(y) < (g_nClientHeight / 2));
}

void PutPixel(IntPoint pt)
{
	if (!IsInRange(pt.X, pt.Y)) return;

	ULONG* dest = (ULONG*)g_pBits;

	int halfWidth = RoundToInt(g_nClientWidth * 0.5f);
	int halfHeight = RoundToInt(g_nClientHeight * 0.5f);

	DWORD offset = (halfHeight * g_nClientWidth - g_nClientWidth * pt.Y) + (halfWidth + pt.X);
	*(dest + offset) = g_CurrentColor;
}

void DrawCall(Mesh * MeshData)
{
	V2F_CUSTOM* v2f = new V2F_CUSTOM[MeshData->iVSize];

	cout << MeshData->iVSize;
	for (int i = 0; i < MeshData->iVSize; i++)
	{
		Vertex v = MeshData->VertexList[i];
		APPDATA_CUSTOM vdata;
		vdata.position = v.mPos;
		vdata.color = v.mColor;
		vdata.uv = v.mUv;
		v2f[i] = VertexShader(vdata);

		//	cout << "\n VertexPosX:"<<v2f[i].position.X; //여기까지는 괜찮음
	}
	/*for (int i = 0; i < MeshData->iISize; i++)
	{
		cout <<endl<<"  "<<i<< v2f[MeshData->IndexList[i]].position.X << endl;;
	}*/

	for (int i = 0; i < MeshData->iISize; i += 3)
	{
		Triangle t(v2f[MeshData->IndexList[i]],
			v2f[MeshData->IndexList[i + 1]],
			v2f[MeshData->IndexList[i + 2]]);

		//	cout <<"\n" <<t.Min.X << t.Max.X<<"====\n";
			//cout << "\n" << t.Min.y << t.Max.y << "====\n";

		for (int y = t.Min.Y; y <= t.Max.Y; y++)
		{
			for (int x = t.Min.X; x <= t.Max.X; x++)
			{
				Vector3 target((float)x + 0.5f, (float)y + 0.5f, 0.0f);
				float outS, outT;
				t.CalcBaryCentricCoord(target, &outS, &outT);
				if (t.IsInTrianble(outS, outT))
				{
					V2F_CUSTOM v2f;
					v2f.position = t.GetFragmentPos(target, outS, outT);
					v2f.color = t.GetFragmentColor(target, outS, outT);
					v2f.uv = t.GetFragmentUV(target, outS, outT);
					ULONG finalColor = FragmentShader(v2f, outS, outT);
					g_CurrentColor = finalColor;
					PutPixel(IntPoint(x, y));
				}
			}
		}
	}

	if (NULL != v2f)
	{
		delete[] v2f;
	}

}

void DrawFillBox(int x1, int y1, int x2, int y2)
{
	UINT offset;
	WORD color565;

	offset = y1 + x1 * 2;
	UINT nextline = (x2 - x1) * 2 - 2;

	int i, j;
	for (i = y1; i <= y2; i++)
	{
		for (j = x1; j <= x2; j++)
		{

			PutPixel(IntPoint(i, j));
		}
		offset += nextline;
	}
}

V2F_CUSTOM VertexShader(APPDATA_CUSTOM in)
{
	// TRS Matrix 반영해서 변환된 position 돌려주기..

	V2F_CUSTOM outputData;

	Matrix3 TMat, RMat, SMat;
	TMat.SetTranslation(0.0f, 0.0f);
	RMat.SetRotation(0);
	SMat.SetScale(1);
	Matrix3 TRSMat = TMat * RMat * SMat;

	outputData.position = in.position * TRSMat;
	outputData.color = in.color;
	outputData.uv = in.uv;

	//	cout << "PositionX:" << outputData.position.X << "\n" << "Color:" << outputData.color << "\n Uv.X:" << outputData.uv.X << "\n";

	return outputData;
}

ULONG FragmentShader(V2F_CUSTOM in, float s, float t)
{
	// Texture에서 색상 빼오기..
	if (g_Texture->IsLoaded())
	{
		return g_Texture->TextureSample(in.uv, s, t);
	}
	return in.color;
}

// 라인그리기
void DrawLine(const Vector3& start, const Vector3& end)
{
	float length = (end - start).Dist();
	float inc = 1.0f / length;

	int maxLength = RoundToInt(length);
	for (int i = 0; i <= maxLength; i++)
	{
		float t = inc * i;
		if (t >= length) t = 1.0f;
		Vector3 Pt = start * (1.0f - t) + end * t;
		PutPixel(Pt.ToIntPoint());
	}
}

////삼각형 그리기
//void Draw2DTriangle(Triangle t)
//{
//	for (int y = t.Min.Y; y <= t.Max.Y; y++)
//	{
//		for (int x = t.Min.X; x <= t.Max.X; x++)
//		{
//			Vector3 target((float)x + 0.5f, (float)y + 0.5f, 0.0f);
//			float outS, outT;
//			t.CalcBaryCentricCoord(target, &outS, &outT);
//			if (t.IsInTrianble(outS, outT))
//			{
//				if (g_Texture->IsLoaded())
//				{
//					g_CurrentColor = g_Texture->GetTexturePixel(outS, outT, t);
//				}
//				else
//				{
//					g_CurrentColor = t.GetPixelColor(target, outS, outT);
//				}
//
//				PutPixel(IntPoint(x, y));
//			}
//		}
//	}
//}
//
//void PutPixel(int x, int y)
//{
//	if (!IsInRange(x, y)) return;
//
//	ULONG* dest = (ULONG*)g_pBits;
//	DWORD offset = g_nClientWidth * g_nClientHeight / 2 + g_nClientWidth / 2 + x + g_nClientWidth * -y;
//	*(dest + offset) = g_CurrentColor;
//}
//
//void PutCircle(int Radius)
//{
//	Vector2 Center(0,0);
//	for (int j = -Radius; j < Radius; j++)
//	{
//		for (int i = -Radius; i < Radius; i++)
//		{
//			Vector2 CurrentPos(i, j);
//			if (Vector2::DistSquared(Center, CurrentPos) <= Radius * Radius)
//			{ 
//				PutPixel(CurrentPos);
//			}
//		}
//	}
//	
//}
//
//
//
//void PutCircle(int Radius,float ScaleA,float ScaleB)
//{
//	Vector2 Center(0, 0);
//	//Matrix2 mMat(0,1,1,0); // 밀기 변환
//	Matrix2 mMat(0,0,0,0); 
//	mMat.SetScale(ScaleA,ScaleB);
//	for (int j = -Radius; j < Radius; j++)
//	{
//		for (int i = -Radius; i < Radius; i++)
//		{
//			Vector2 CurrentPos(i, j);
//			Vector2 OutPos =  CurrentPos * mMat;
//			if (Vector2::DistSquared(Center, CurrentPos) <=Radius * Radius)
//			{
//				PutPixel(OutPos);
//			}
//		}
//	}
//
//}

void InitFrame(void)
{

}
bool bInit = false;
void UpdateFrame(void)
{
	SetColor(32, 128, 255);
	Clear();

	// Draw
	Vector3 Pt1, Pt2, Pt3, Pt4;

	static float offsetX = 0.0f;
	static float angle = 0.0f;
	static float scale = 1.0f;

	if (GetAsyncKeyState(VK_LEFT)) offsetX -= 1.0f;
	if (GetAsyncKeyState(VK_RIGHT)) offsetX += 1.0f;
	if (GetAsyncKeyState(VK_UP)) angle += 1.0f;
	if (GetAsyncKeyState(VK_DOWN)) angle -= 1.0f;
	if (GetAsyncKeyState(VK_PRIOR)) scale *= 1.01f;
	if (GetAsyncKeyState(VK_NEXT)) scale *= 0.99f;


	//	InitFrame();


	Vertex  Rect[4];
	int  indexlist[6] = { 0,1,2,0,2,3 };

	Rect[0] = Vertex(Vector3(0, 0, 0));
	Rect[0].mColor = RGB32(255, 0, 0);
	Rect[0].mUv = Vector2(0.125f, 0);

	Rect[1] = Vertex(Vector3(0, 150, 0));
	Rect[1].mColor = RGB32(255, 255, 0);
	Rect[1].mUv = Vector2(0.125f, 0.2f);

	Rect[2] = Vertex(Vector3(150, 150, 0));
	Rect[2].mColor = RGB32(255, 0, 255);
	Rect[2].mUv = Vector2(0.2f, 0.2f);

	Rect[3] = Vertex(Vector3(150, 0, 0));
	Rect[3].mColor = RGB32(255, 255, 255);
	Rect[3].mUv = Vector2(0.2f, 0.125f);

	//g_CurrentColor = RGB32(255, 0, 0);
	Mesh* m = new Mesh();
	m->CreateMesh(Rect, 4, indexlist, 6);
	DrawCall(m);


	//SetColor(255, 0, 0);
	//g_CurrentColor = RGB(0, 0, 255);
	//DrawFillBox(20, 20, 100, 100);
	/*g_CurrentColor = RGB32(255, 0, 0);
	PutPixel(IntPoint(0, 0));
	PutPixel(IntPoint(150, 150));*/

	// Mesh가 생성되면 Mesh의 다각형을 버텍스 -> 픽셀 셰이더로 돌려 색과 위치를 결정하고 그려주기 추가로 깊이버퍼나 그런 값들 넣어주기


	//Matrix3 TMat, RMat, SMat;
	//TMat.SetTranslation(offsetX, 0.0f);
	//RMat.SetRotation(angle);
	//SMat.SetScale(scale);
	//Matrix3 TRSMat = TMat * RMat * SMat;
	//
	//Pt1.SetPoint(-150, 150.0f);
	//Pt2.SetPoint(150.0f, 150.0f);
	//Pt3.SetPoint(150.0f, -150.0f);
	//Pt4.SetPoint(-150.0f, -150.0f);
	//
	//Vertex v1(Pt1 * TRSMat);
	//v1.mColor = RGB32(255, 0, 0);
	////v1.uv = Vector2(0.0f, 0.0f);
	//v1.mUv = Vector2(0.125f, 0.125f);
	//Vertex v2(Pt2 * TRSMat);
	//v2.mColor = RGB32(0, 255, 0);
	////v2.uv = Vector2(1.0f, 0.0f);
	//v2.mUv = Vector2(0.25f, 0.125f);
	//Vertex v3(Pt3 * TRSMat);
	//v3.mColor = RGB32(0, 0, 255);
	////v3.uv = Vector2(1.0f, 1.0f);
	//v3.mUv = Vector2(0.25f, 0.25f);
	//Triangle T1(v1, v2, v3);
	//
	//Vertex v4(Pt4 * TRSMat);
	//v4.mColor = RGB32(255, 255, 0);
	////v4.uv = Vector2(0.0f, 1.0f);
	//v4.mUv = Vector2(0.125f, 0.25f);
	//Triangle T2(v1, v4, v3);
	//
	//Draw2DTriangle(T1);
	//Draw2DTriangle(T2);

	// Buffer Swap 
	BufferSwap();
}
