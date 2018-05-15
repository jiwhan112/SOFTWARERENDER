#include "stdafx.h"
#include "Mesh.h"

Mesh::~Mesh()
{
	if (NULL != VertexList)
	{
		delete[] VertexList;
		VertexList = NULL;
	}

	if (NULL != IndexList)
	{
		delete[] IndexList;
		IndexList = NULL;
	}
	if (NULL != TriIndexList)
	{
		delete[] TriIndexList;
		TriIndexList = NULL;
	}
}



void Mesh::CreateMesh(size_t VSize, size_t ISize)
{
	iVSize = VSize;
	VertexList = new Vertex[VSize];

	iISize = ISize;
	IndexList = new int[ISize];

	TriIndexList = new int[iISize / 3];

	bCreate = true;

}

void Mesh::CreateMesh(Vertex * vertex, size_t VSize, int * indexList, size_t ISize)
{
	iVSize = VSize;
	VertexList = vertex;

	iISize = ISize;
	IndexList = indexList;

	TriIndexList = new int[iISize / 3];

	bCreate = true;

}




