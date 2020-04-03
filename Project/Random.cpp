#include "Random.h"

Random::Random()
{
	srand((unsigned)time(NULL));
}

float Random::random()
{
	return rand();
}