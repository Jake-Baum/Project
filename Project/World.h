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
  unsigned int cameraPositionId;
  GLFWwindow* window;
  Camera camera;
  double currentTime;
  double prevTime;
  Input input;

public:
  World(GLFWwindow*, unsigned int programId, Camera, unsigned int cameraPositionId);
  static glm::i32vec2 initWindowSize(GLFWwindow*);
  void addCube(Cube);
  std::vector<Cube> getCubes();
  void start();
  void update();
  void draw();
};