#include "Cube.h"

Cube::Cube(Shaders *shaders, Camera *camera, glm::vec3 position) : Object(shaders, camera)
{
  std::vector<glm::vec3> normalBufferData;
  normalBufferData.push_back(glm::normalize(LEFT + DOWN + FORWARD));
  normalBufferData.push_back(glm::normalize(LEFT + DOWN + BACKWARD));
  normalBufferData.push_back(glm::normalize(LEFT + UP + BACKWARD));
  normalBufferData.push_back(glm::normalize(RIGHT + UP + FORWARD));
  normalBufferData.push_back(glm::normalize(LEFT + UP + FORWARD));
  normalBufferData.push_back(glm::normalize(RIGHT + DOWN + BACKWARD));
  normalBufferData.push_back(glm::normalize(RIGHT + DOWN + FORWARD));
  normalBufferData.push_back(glm::normalize(RIGHT + UP + BACKWARD));

  std::vector<Vertex> vertexBufferData;
  for (int i = 0; i < numVertices; i++)
  {
    Vertex vertex;
    vertex.position = glm::vec3(vertices[i][0], vertices[i][1], vertices[i][2]);
    vertex.colour = glm::vec3(colours[i][0], colours[i][1], colours[i][2]);
    vertex.normal = glm::vec3(normalBufferData[i]);
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