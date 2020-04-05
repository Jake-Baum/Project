#pragma once

#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

class Time
{
private:
	static float prevTime;
	static float currentTime;

public:
	static float deltaTime;

	static void update();
};