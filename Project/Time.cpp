#include "Time.h"

float Time::prevTime = 0;
float Time::currentTime = 0;
float Time::deltaTime = 0;

void Time::update()
{
	prevTime = currentTime;
	currentTime = glfwGetTime();
 	deltaTime = float(currentTime - prevTime);
}