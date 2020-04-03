#pragma once

#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

struct Vertex
{
  glm::vec3 position;
  glm::vec3 colour;
  glm::vec3 normal;
};

class Mesh
{
public:
  std::vector<unsigned int> indices;
  std::vector<Vertex> vertices;

  Mesh();
  Mesh(std::vector<unsigned int> indices, std::vector<Vertex> vertices);
};