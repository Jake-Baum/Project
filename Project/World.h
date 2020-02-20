#pragma once

#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

#include "Cube.h"
#include "Camera.h"
#include "Input.h"

class World
{
private:
  std::vector<Cube> cubes;
  unsigned int programId;
  GLFWwindow* window;
  Camera camera;
  double currentTime;
  double prevTime;
  Input input;

public:
  World(GLFWwindow*, unsigned int programId, Camera);
  static glm::i32vec2 initWindowSize(GLFWwindow*);
  void addCube(Cube);
  std::vector<Cube> getCubes();
  void update();
  void draw();
};