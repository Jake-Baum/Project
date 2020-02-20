#include "Camera.h"

Camera::Camera()
{
	projection = glm::perspective(glm::radians(fov), 4.0f / 3.0f, 0.1f, 100.f);
	position = glm::vec3(0, 3, 10);
	direction = glm::vec3(0, 0, -1);
	angle.x = 3.14f;
	angle.y = 0.0f;
}

glm::vec3 Camera::getPosition()
{
	return position;
}

glm::vec2 Camera::getAngle()
{
	return angle;
}

float Camera::getSpeed()
{
	return speed;
}

void Camera::translate(glm::vec3 velocity)
{
	position += velocity;
}

void Camera::rotate(glm::vec2 rotation)
{
	angle += rotation;
	direction = glm::vec3(cos(angle.y) * sin(angle.x), sin(angle.y), cos(angle.y) * cos(angle.x));
}

glm::mat4 Camera::getViewMatrix()
{
	return glm::lookAt(position, //where camera is in world space
	position + direction, //look forwards
	glm::vec3(0, 1, 0) //camera oriented vertically
	);
}

glm::mat4 Camera::getVp()
{
	return projection * getViewMatrix();
}