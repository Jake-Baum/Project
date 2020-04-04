#include "Random.h"

Random::Random()
{
	srand((unsigned)time(NULL));
}

float Random::random()
{
	return (float)(rand() / (float)RAND_MAX);
}