#pragma once

#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

#include "Camera.h"`

class Input
{
private:
	float mouseSpeed = 0.5f;
	glm::i32vec2 windowSize;
	glm::f64vec2 mouseCoords;

public:
	Input();
	Input(glm::i32vec2);
	void handleInput(GLFWwindow *, Camera *);
	glm::f64vec2 getMouseCoords();
};