#include "Camera.h"

Camera::Camera(Shaders *shaders)
{
	this->shaders = shaders;
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

glm::vec3 Camera::getDirection()
{
	return direction;
}

//returns a vector perpendicular to direction and up vector
glm::vec3 Camera::getRight()
{
	return glm::cross(direction, UP);
}

glm::vec2 Camera::getAngle()
{
	return angle;
}

void Camera::translate(glm::vec3 velocity)
{
	position += velocity;
}

void Camera::rotate(glm::vec2 rotation)
{
	//limit maximum rotation
	//this was initially added because my cursor keeps glitching out on this PC
	if (rotation.x > 0.05)rotation.x = 0.05;
	if (rotation.x < -0.05)rotation.x = -0.05;
	if (rotation.y > 0.05)rotation.y = 0.05;
	if (rotation.y < -0.05)rotation.y = -0.05;
	
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

void Camera::update()
{
	glUniform3fv(shaders->uniformIds.cameraPositionId, 1, &getPosition()[0]);
}