#pragma once
#include <string>
#include <vector>
#include "Model.h"
#include <glm\glm.hpp>
#include "Loader.h"

class ObjLoader
{
public:

	Model LoadObjToModel(std::string filePath, Loader loader);

private:

	void HandleVertices(const std::vector<std::string>& vertex, const std::vector<glm::vec2>& textureCoords, std::vector<float>& newTextureCoords, 
		const std::vector<glm::vec3>& normals, std::vector<float>& newNormals, std::vector<unsigned int>& indices);
};