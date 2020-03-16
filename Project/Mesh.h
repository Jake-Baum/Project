#pragma once

#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

#include "Camera.h"

struct Vertex
{
  glm::vec3 position;
  glm::vec3 colour;
  glm::vec3 normal;
};

class Mesh
{
private:
  Shaders* shaders;
  Camera *camera;

	glm::vec3 position;

  std::vector<unsigned int> indices;

  std::vector<Vertex> vertices;

  unsigned int vertexBuffer;
  unsigned int indexBuffer;
  unsigned int colourBuffer;
  unsigned int normalBuffer;

public:
  Mesh(Shaders *, Camera *);

  void setPosition(glm::vec3);
  glm::vec3 getPosition();

  std::vector<Vertex> getVertices();
  void setVertices(std::vector<Vertex>);
  void setIndices(std::vector<unsigned int>);

  glm::mat4 getModelMatrix();
  glm::mat4 getNormalMatrix();

  void update();
  void draw();
  void translate(glm::vec3);
  void rotate();
  void scale(glm::vec3);

};