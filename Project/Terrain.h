 #pragma once

#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

#include "Object.h"
#include "Mesh.h"

class Terrain : public Object
{
public:
  unsigned int numVertices;
  unsigned int numIndices;

  unsigned int width;
  unsigned int length;

public:
  Terrain(Shaders*, Camera*, glm::vec3, unsigned int width, unsigned int length);
};