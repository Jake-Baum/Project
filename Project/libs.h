#pragma once
//OpenGL libraries
#include <glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
//#include <glm/gtx/quaternion.hpp>

//Standard libraries
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

//Custom libraries
#include "Shaders.h"
#include "Random.h"

const glm::vec3 LEFT(-1, 0, 0);
const glm::vec3 RIGHT(1, 0, 0);
const glm::vec3 UP(0, 1, 0);
const glm::vec3 DOWN(0, -1, 0);
const glm::vec3 FORWARD(0, 0, -1);
const glm::vec3 BACKWARD(0, 0, 1);