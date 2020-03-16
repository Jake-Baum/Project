#include "Mesh.h"

Mesh::Mesh(Shaders *shaders, Camera *camera)
{
  this->shaders = shaders;
  this->camera = camera;
}

glm::vec3 Mesh::getPosition()
{
	return position;
}

void Mesh::setPosition(glm::vec3 position)
{
	this->position = position;
}

std::vector<Vertex> Mesh::getVertices()
{
  return vertices;
}

void Mesh::setVertices(std::vector<Vertex> vertices)
{
  this->vertices = vertices;

  glGenBuffers(1, &vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
}

void Mesh::setIndices(std::vector<unsigned int> indices)
{
  this->indices = indices;

  glGenBuffers(1, &indexBuffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
}

glm::mat4 Mesh::getModelMatrix()
{
  return glm::translate(glm::mat4(1.0f), position);
}

glm::mat4 Mesh::getNormalMatrix()
{
  return glm::mat3(glm::transpose(glm::inverse(getModelMatrix())));
}

void Mesh::update()
{

}

void Mesh::draw()
{
  glm::mat4 mvp = camera->getVp() * getModelMatrix();
  glUniformMatrix4fv(shaders->uniformIds.mvpId, 1, GL_FALSE, &mvp[0][0]);
  glm::mat3 normalMatrix = getNormalMatrix();
  glUniformMatrix3fv(shaders->uniformIds.normalMatrixId, 1, GL_FALSE, &normalMatrix[0][0]);

  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, colour));

  glEnableVertexAttribArray(2);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); 
  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

  glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
}

void Mesh::translate(glm::vec3 translation)
{
	position += translation;
}