#pragma once
#include <string>
#include <GL\glew.h>
#include <glm\glm.hpp>
#include "Camera.h"
#include "Light.h"

class Shader
{
public:

	Shader(const std::string& vertexPath, const std::string& fragmentPath);

	void LoadTransformationMatrix(const glm::mat4& matrix);
	void LoadViewMatrix(const Camera& camera);
	void LoadProjectionMatrix();
	void LoadLight(const Light& light);
	void LoadSpecularVariables(float reflectivity, float damper);

	void SetFloat(const std::string& name, float value);
	void SetVec3(const std::string& name, const glm::vec3& value);
	void SetMat4(const std::string& name, const glm::mat4& value);

	void Start();
	void Stop();

private:

	void LinkProgram(unsigned int vertexID, unsigned int fragmentID);
	unsigned int CompileShader(const std::string& shaderSource, const GLenum& shaderType);

	int GetUniformLocation(const std::string& name);

private:

	unsigned int programID;
};