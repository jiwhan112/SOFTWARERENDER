#pragma once

#include"stdafx.h"
#include "Vertex.h"

class Mesh
{
public:
	Mesh() : VertexList(NULL), IndexList(NULL), TriIndexList(NULL), iISize(0), iVSize(0), bCreate(false){ }
	~Mesh();

	void CreateMesh(size_t VSize, size_t ISize);
	void CreateMesh(Vertex * vertex, size_t VSize, int * indexList,size_t ISize);

	Vertex* VertexList;
	int* IndexList;
	int *TriIndexList;
	int iISize;
	int iVSize;

	bool bCreate;

};

