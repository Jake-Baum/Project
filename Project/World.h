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
  std::vector<Object *> objects;
  GLFWwindow* window;
  Camera *camera;
  double currentTime;
  double prevTime;
  Input input;

public:
  Shaders *shaders;

  World(GLFWwindow*, Shaders *shaders, Camera *camera);
  Camera *getCamera();
  static glm::i32vec2 initWindowSize(GLFWwindow*);
  void addObject(Object *);
  std::vector<Object *> getObjects();
  void start();
  void update();
  void draw();
};