#pragma once
#include <glm\glm.hpp>

class Light
{
public:

	Light(glm::vec3 pos, glm::vec3 colour);

	glm::vec3 GetPosition() const;
	void SetPosition(glm::vec3 pos);

	glm::vec3 GetColour() const;
	void SetColour(glm::vec3 colour);

private:
	glm::vec3 position;
	glm::vec3 colour;
};