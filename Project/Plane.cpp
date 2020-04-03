#include "Plane.h"

Plane::Plane(Shaders* shaders, Camera* camera, glm::vec3 position) : Object(shaders, camera)
{
  std::vector<Vertex> vertexBufferData;
  for (int i = 0; i < numVertices; i++)
  {
    Vertex vertex;
    vertex.position = glm::vec3(vertices[i][0], vertices[i][1], vertices[i][2]);
    vertex.colour = glm::vec3(colours[i][0], colours[i][1], colours[i][2]);
    vertex.normal = UP;
    vertexBufferData.push_back(vertex);
  }
  std::vector<unsigned int> indexBufferData;
  for (int i = 0; i < numIndices; i++)
  {
    indexBufferData.push_back(indices[i]);
  }

  this->position = position;
  this->mesh.vertices = vertexBufferData;
  this->mesh.indices = indexBufferData;
}