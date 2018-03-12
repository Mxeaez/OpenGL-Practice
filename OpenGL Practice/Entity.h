#pragma once
#include "TexturedModel.h"
#include <glm\glm.hpp>

class Entity
{
public:

	Entity(TexturedModel model, glm::vec3 position, float rx, float ry, float rz, float scale);

	void IncreasePosition(float x, float y, float z);
	void IncreaseRotation(float x, float y, float z);

	TexturedModel GetTexturedModel() const;
	void SetTexturedModel(const TexturedModel& texturedModel);

	glm::vec3 GetPosition() const;
	void SetPosition(const glm::vec3& pos);

	float GetRotX() const;
	void SetRotX(float rotation);

	float GetRotY() const;
	void SetRotY(float rotation);

	float GetRotZ() const;
	void SetRoyZ(float rotation);

	float GetScale() const;
	void SetScale(float newScale);

private:
	TexturedModel model;
	glm::vec3 position;
	float rx, ry, rz;
	float scale;
};