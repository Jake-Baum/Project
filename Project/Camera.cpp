#include "Camera.h"

Camera::Camera()
{
	projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.f);
	position = glm::vec3(0, 3, 10);
	direction = glm::vec3(0, 0, -1);
}

glm::vec3 Camera::getPosition()
{
	return position;
}

float Camera::getSpeed()
{
	return speed;
}

void Camera::translate(glm::vec3 velocity)
{
	position += velocity;
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