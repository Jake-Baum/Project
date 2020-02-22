#pragma once

#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

class Camera
{
private:
	glm::mat4 projection;
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec2 angle;

public:
	float speed = 3.0f;
	float fov = 45.0f;

	Camera();
	glm::mat4 getViewMatrix();
	glm::vec3 getPosition();
	glm::vec3 getDirection();
	glm::vec3 getRight();
	glm::vec2 getAngle();
	void translate(glm::vec3);
	void rotate(glm::vec2);
	glm::mat4 getVp();
};