#pragma once
#include <string>
#include <GL\glew.h>
#include <glm\glm.hpp>

class Shader
{
public:

	Shader(const std::string& vertexPath, const std::string& fragmentPath);

	void LoadTransformationMatrix(const glm::mat4& matrix);
	void LoadViewMatrix();

	int GetUniformLocation(const std::string& name);

	void SetFloat(const std::string& name, float value);
	void SetVec3(const std::string& name, const glm::vec3& value);
	void SetMat4(const std::string& name, const glm::mat4& value);

	void Bind();

private:

	void LinkProgram(unsigned int vertexID, unsigned int fragmentID);
	unsigned int CompileShader(const std::string& shaderSource, const GLenum& shaderType);

	void LoadProjectionMatrix();

private:

	unsigned int programID;
};