#include "Time.h"

float Time::prevTime;
float Time::currentTime;
float Time::deltaTime;

void Time::update()
{
	prevTime = currentTime;
	currentTime = glfwGetTime();
 	deltaTime = float(currentTime - prevTime);
}