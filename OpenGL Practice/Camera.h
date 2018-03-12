#pragma once
#include <glm\glm.hpp>

class Camera
{
public:

	Camera();
	Camera(glm::vec3 pos, float pitch, float yaw, float roll);

	void Move();

	glm::vec3 GetPosition() const;
	void SetPosition(const glm::vec3& pos);

	float GetPitch() const;
	void SetPitch(float degrees);

	float GetYaw() const;
	void SetYaw(float degrees);
	
	float GetRoll() const;
	void SetRoll(float degrees);

private:
	glm::vec3 position;
	float pitch;
	float yaw;
	float roll;

};