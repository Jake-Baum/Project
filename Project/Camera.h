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
	float speed = 3.0f;

public:
	Camera();
	glm::mat4 getViewMatrix();
	glm::vec3 getPosition();
	float getSpeed();
	void translate(glm::vec3);
	glm::mat4 getVp();
};