#include "Shader.h"
#include "Utility.h"
#include <iostream>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "WindowManager.h"
#include "Math.h"

Shader::Shader(const std::string & vertexPath, const std::string & fragmentPath)
{

	std::string vertexSource = Utility::GetFileSource(vertexPath);
	std::string fragmentSource = Utility::GetFileSource(fragmentPath);

	unsigned int vertexID = CompileShader(vertexSource, GL_VERTEX_SHADER);
	unsigned int fragmentID = CompileShader(fragmentSource, GL_FRAGMENT_SHADER);

	LinkProgram(vertexID, fragmentID);

	Bind();
	LoadProjectionMatrix();
	glUseProgram(0);

}

void Shader::LoadTransformationMatrix(const glm::mat4 & matrix)
{
	SetMat4("transformationMatrix", matrix);
}

void Shader::LoadViewMatrix(const Camera& camera)
{
	glm::mat4 viewMatrix = Math::CreateViewMatrix(camera);
	SetMat4("viewMatrix", viewMatrix);
}

void Shader::LoadLight(const Light & light)
{
	SetVec3("lightPosition", light.GetPosition());
	SetVec3("lightColour", light.GetColour());
}

void Shader::LoadSpecularVariables(float reflectivity, float damper)
{
	SetFloat("reflectivity", reflectivity);
	SetFloat("damper", damper);
}

void Shader::SetFloat(const std::string & name, float value)
{
	int location = GetUniformLocation(name);
	glUniform1f(location, value);
}

void Shader::SetVec3(const std::string & name, const glm::vec3 & value)
{
	int location = GetUniformLocation(name);
	glUniform3f(location, value.x, value.y, value.z);
}

void Shader::SetMat4(const std::string & name, const glm::mat4 & value)
{
	int location = GetUniformLocation(name);
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::Bind()
{
	glUseProgram(programID);
}

void Shader::LinkProgram(unsigned int vertexID, unsigned int fragmentID)
{
	programID = glCreateProgram();

	glAttachShader(programID, vertexID);
	glAttachShader(programID, fragmentID);
	glLinkProgram(programID);

	int success;
	char infoLog[512];

	glGetProgramiv(programID, GL_LINK_STATUS, &success);

	if (success != GL_TRUE)
	{
		glGetProgramInfoLog(programID, 512, nullptr, infoLog);
		std::cout << "Program linking failed: " << infoLog << std::endl;

		glDetachShader(programID, vertexID);
		glDetachShader(programID, fragmentID);
		glDeleteShader(vertexID);
		glDeleteShader(fragmentID);
	}
}

unsigned int Shader::CompileShader(const std::string & shaderSource, const GLenum& shaderType)
{

	unsigned int shaderID = glCreateShader(shaderType);

	const char* source = shaderSource.c_str();
	glShaderSource(shaderID, 1, &source, nullptr);
	glCompileShader(shaderID);

	int success;
	char infoLog[512];

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

	if (success != GL_TRUE)
	{
		glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);

		std::cout << "Failed to compile shader: " << infoLog << std::endl;

		glDeleteShader(shaderID);
	}

	return shaderID;

}

void Shader::LoadProjectionMatrix()
{
	glm::mat4 matrix = glm::perspective(glm::radians(45.0f), (float)WindowManager::WIDTH / (float)WindowManager::HEIGHT, 0.1f, 1000.0f);
	SetMat4("projectionMatrix", matrix);
}


int Shader::GetUniformLocation(const std::string & name)
{
	int location = glGetUniformLocation(programID, name.c_str());

	return location;
}