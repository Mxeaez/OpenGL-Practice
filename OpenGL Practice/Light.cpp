#include "Light.h"

Light::Light(glm::vec3 pos, glm::vec3 colour)
	: position(pos)
	, colour(colour)
{
}

glm::vec3 Light::GetPosition() const
{
	return position;
}

void Light::SetPosition(glm::vec3 pos)
{
	position = pos;
}

glm::vec3 Light::GetColour() const
{
	return colour;
}

void Light::SetColour(glm::vec3 colour)
{
	Light::colour = colour;
}
