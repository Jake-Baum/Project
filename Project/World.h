#pragma once

#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

#include "Cube.h"

class World
{
private:
  std::vector<Cube> cubes;
  unsigned int programId;
  GLFWwindow* window;

public:
  World(GLFWwindow*, unsigned int programId);
  void addCube(Cube);
  std::vector<Cube> getCubes();
  void draw();
};