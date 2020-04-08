#include "Time.h"

double Time::prevTime = 0;
double Time::currentTime = 0;
float Time::deltaTime = 0;

void Time::update()
{
	prevTime = currentTime;
	currentTime = glfwGetTime();
 	deltaTime = currentTime - prevTime;
}