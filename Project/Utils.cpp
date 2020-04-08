#include "Utils.h"

std::string Utils::vec3ToString(glm::vec3 v)
{
	return std::to_string(v.x) + std::to_string(v.y) + std::to_string(v.z);
}