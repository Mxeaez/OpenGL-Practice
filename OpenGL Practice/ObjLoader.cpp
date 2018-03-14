#include "ObjLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Utility.h"

Model ObjLoader::LoadObjToModel(std::string filePath, Loader loader)
{

	std::ifstream inFile(filePath);

	if (!inFile)
	{
		std::cout << "Failed to load Obj failed: " << filePath << std::endl;
	}

	std::vector<float> vertices;
	std::vector<glm::vec2> textureCoords;
	std::vector<glm::vec3> normals;
	std::vector<unsigned int> indices;

	std::vector<float> newTextureCoords;
	std::vector<float> newNormals;
	bool allocatedNewVectors = false;

	std::string line;
	std::string decider;

	float v1, v2, v3;

	for (std::getline(inFile, line); inFile; std::getline(inFile, line))
	{
		std::stringstream stream(line);
		stream >> decider;

		if (decider == "v")
		{
			stream >> v1 >> v2 >> v3;
			vertices.push_back(v1);
			vertices.push_back(v2);
			vertices.push_back(v3);
		}
		else if (decider == "vt")
		{
			stream >> v1 >> v2;
			textureCoords.push_back(glm::vec2(v1, v2));
		}
		else if (decider == "vn")
		{
			stream >> v1 >> v2 >> v3;
			normals.push_back(glm::vec3(v1, v2, v3));
		}
		else if (decider == "f")
		{
			if (!allocatedNewVectors)
			{
				allocatedNewVectors = true;
				newTextureCoords.resize(vertices.size() * 2);
				newNormals.resize(vertices.size() * 3);
			}
			std::vector<std::string> vertexes(3);
			stream >> vertexes[0] >> vertexes[1] >> vertexes[2];

			std::vector<std::string> vertex1 = Utility::Split(vertexes[0], "/"); //41, 1, 1
			std::vector<std::string> vertex2 = Utility::Split(vertexes[1], "/"); // 38, 2, 1
			std::vector<std::string> vertex3 = Utility::Split(vertexes[2], "/"); // 45, 3, 1

			HandleVertices(vertex1, textureCoords, newTextureCoords, normals, newNormals, indices);
			HandleVertices(vertex2, textureCoords, newTextureCoords, normals, newNormals, indices);
			HandleVertices(vertex3, textureCoords, newTextureCoords, normals, newNormals, indices);
		}
		std::cout << "Working." << std::endl;
	}

	Model model = loader.LoadToVAO(vertices, newTextureCoords, newNormals, indices);

	return model;
}

void ObjLoader::HandleVertices(const std::vector<std::string>& vertex, const std::vector<glm::vec2>& textureCoords, std::vector<float>& newTextureCoords,
	const std::vector<glm::vec3>& normals, std::vector<float>& newNormals, std::vector<unsigned int>& indices)
{
	unsigned int vertexPointer = std::stoi(vertex[0]) - 1;
	indices.push_back(vertexPointer);

	newTextureCoords[vertexPointer * 2] = textureCoords[std::stoi(vertex[1]) - 1].x;
	newTextureCoords[vertexPointer * 2 + 1] = 1 - (textureCoords[std::stoi(vertex[1]) - 1].y);

	newNormals[vertexPointer * 3] = normals[std::stoi(vertex[2]) - 1].x;
	newNormals[vertexPointer * 3 + 1] = normals[std::stoi(vertex[2]) - 1].y;
	newNormals[vertexPointer * 3 + 2] = normals[std::stoi(vertex[2]) - 1].z;
}
