#pragma once

#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

#include "Object.h"
#include "Mesh.h"

class Plane : public Object
{
public:
  static const unsigned int numVertices = 4;
  static const unsigned int numIndices = 6;

private:
  static constexpr GLfloat vertices[][3] =
  {
      {-1.0f, 0.0f,-1.0f},//0
      {-1.0f, 0.0f, 1.0f},//1
      {1.0f, 0.0f, -1.0f},//2
      {1.0f, 0.0f, 1.0f}//3
  };

  static constexpr unsigned int indices[] =
  {
      0,1,2,
      1,2,3
  };


  static constexpr GLfloat colours[][3] =
  {
      {0.583f,  0.771f,  0.014f},
      {0.609f,  0.115f,  0.436f},
      {0.327f,  0.483f,  0.844f},
      {0.822f,  0.569f,  0.201f}
  };

public:
  Plane(Shaders*, Camera*, glm::vec3);
};