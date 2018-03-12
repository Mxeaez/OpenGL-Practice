#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "Camera.h"

namespace Math
{
	static glm::mat4 CreateTransformationMatrix(glm::vec3 position, float rx, float ry, float rz, float scale)
	{
		glm::mat4 matrix = glm::mat4(1.0f);
		matrix = glm::translate(matrix, position);
		matrix = glm::rotate(matrix, glm::radians(rx), glm::vec3(1, 0, 0));
		matrix = glm::rotate(matrix, glm::radians(ry), glm::vec3(0, 1, 0));
		matrix = glm::rotate(matrix, glm::radians(rz), glm::vec3(0, 0, 1));
		matrix = glm::scale(matrix, glm::vec3(scale, scale, scale));

		return matrix;
	}

	static glm::mat4 CreateViewMatrix(const Camera& camera)
	{
		glm::mat4 matrix = glm::mat4(1.0f);
		matrix = glm::rotate(matrix, glm::radians(camera.GetPitch()), glm::vec3(1, 0, 0));
		matrix = glm::rotate(matrix, glm::radians(camera.GetYaw()), glm::vec3(0, 1, 0));
		glm::vec3 cameraPos = camera.GetPosition();
		glm::vec3 negativeCameraPos = glm::vec3(-cameraPos.x, -cameraPos.y, -cameraPos.z);
		matrix = glm::translate(matrix, negativeCameraPos);

		return matrix;
	}
	
}