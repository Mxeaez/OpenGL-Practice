#pragma once
#include <SFML\Graphics.hpp>
#include <string>

class Model
{
public:

	Model(unsigned int vaoID, int vertexCount);

	unsigned int GetVaoID();
	int GetVertexCount();

private:

	unsigned int vaoID;
	int vertexCount;
};