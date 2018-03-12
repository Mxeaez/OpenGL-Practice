#include "Model.h"
#include <iostream>

Model::Model(unsigned int vaoID, int vertexCount)
	: vaoID(vaoID)
	, vertexCount(vertexCount)
{
}

unsigned int Model::GetVaoID()
{
	return vaoID;
}

int Model::GetVertexCount()
{
	return vertexCount;
}