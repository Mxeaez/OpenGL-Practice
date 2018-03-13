#include "Loader.h"
#include <GL\glew.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Model Loader::LoadToVAO(const std::vector<float>& vertexData, const std::vector<float>& textureCoords, const std::vector<unsigned int> indices)
{
	unsigned int vaoID = CreateVAO(vertexData);
	BindEBO(indices);
	StoreDataInAttributeList(0, 3, vertexData);
	StoreDataInAttributeList(1, 2, textureCoords);

	return Model(vaoID, indices.size());
}

unsigned int Loader::LoadTexture(const std::string& imageName) const
{

	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	int width, height, nrChannels;
	unsigned char *data = stbi_load(imageName.c_str(), &width, &height, &nrChannels, 0);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture: " << imageName << std::endl;
	}
	stbi_image_free(data);

	return texture;
}

void Loader::BindEBO(const std::vector<unsigned int> indices)
{
	unsigned int eboID;
	glGenBuffers(1, &eboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), indices.data(), GL_STATIC_DRAW);
}

unsigned int Loader::CreateVAO(const std::vector<float>& positions)
{
	unsigned int vaoID;
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);
	
	return vaoID;
}

void Loader::StoreDataInAttributeList(int attributeNumber, int size, const std::vector<float>& vertexData)
{
	unsigned int vboID;
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData[0]) * vertexData.size(), vertexData.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(attributeNumber, size, GL_FLOAT, GL_FALSE, 0, 0);
}
