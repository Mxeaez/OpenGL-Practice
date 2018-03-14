#pragma once
#include "Model.h"
#include <vector>
#include <string>

class Loader
{
public:
	Model LoadToVAO(const std::vector<float>& vertexData, const std::vector<float>& textureCoords, const std::vector<float>& normals, const std::vector<unsigned int>& indices);
	unsigned int LoadTexture(const std::string& imageName) const;

private:

	void BindEBO(const std::vector<unsigned int>& indices);
	unsigned int CreateVAO(const std::vector<float>& positions);
	void StoreDataInAttributeList(int attributeNumber, int size, const std::vector<float>& vertexData);
};