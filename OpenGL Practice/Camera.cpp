#include "Camera.h"
#include <SFML\Graphics.hpp>

Camera::Camera()
	: position(glm::vec3(1.0f, 0, 0))
	, pitch(0.0f)
	, yaw(0.0f)
	, roll(0.0f)
{
}

Camera::Camera(glm::vec3 pos, float pitch, float yaw, float roll)
	: position(pos)
	, pitch(pitch)
	, yaw(yaw)
	, roll(roll)
{
}

void Camera::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		position.z -= 0.002;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		position.x -= 0.002;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		position.x += 0.002;
	}
}

glm::vec3 Camera::GetPosition() const
{
	return position;
}

void Camera::SetPosition(const glm::vec3 & pos)
{
	position = pos;
}

float Camera::GetPitch() const
{
	return pitch;
}

void Camera::SetPitch(float degrees)
{
	pitch = degrees;
}

float Camera::GetYaw() const
{
	return yaw;
}

void Camera::SetYaw(float degrees)
{
	yaw = degrees;
}

float Camera::GetRoll() const
{
	return roll;
}

void Camera::SetRoll(float degrees)
{
	roll = degrees;
}
