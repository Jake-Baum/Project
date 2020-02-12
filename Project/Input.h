#pragma once

#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

#include "Camera.h"`

class Input
{
private:
	glm::vec2 mouseCoords;

public:
	Input();
	void handleInput(GLFWwindow*, float, Camera&);
};