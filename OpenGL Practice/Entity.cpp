#include "Entity.h"

Entity::Entity(TexturedModel model, glm::vec3 position, float rx, float ry, float rz, float scale)
	: model(model)
	, position(position)
	, rx(rx)
	, ry(ry)
	, rz(rz)
	, scale(scale)
{
}

void Entity::IncreasePosition(float x, float y, float z)
{
	position.x += x;
	position.y += y;
	position.z += z;
}

void Entity::IncreaseRotation(float x, float y, float z)
{
	rx += x;
	ry += y;
	rz += z;
}

TexturedModel Entity::GetTexturedModel() const
{
	return model;
}

void Entity::SetTexturedModel(const TexturedModel& texturedModel)
{
	model = texturedModel;
}

glm::vec3 Entity::GetPosition() const
{
	return position;
}

void Entity::SetPosition(const glm::vec3& pos)
{
	position = pos;
}

float Entity::GetRotX() const
{
	return rx;
}

void Entity::SetRotX(float rotation)
{
	rx = rotation;
}

float Entity::GetRotY() const
{
	return ry;
}

void Entity::SetRotY(float rotation)
{
	ry = rotation;
}

float Entity::GetRotZ() const
{
	return rz;
}

void Entity::SetRoyZ(float rotation)
{
	rz = rotation;
}

float Entity::GetScale() const
{
	return scale;
}

void Entity::SetScale(float newScale)
{
	scale = newScale;
}
