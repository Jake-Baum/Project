#include "Object.h"

Object::Object(Shaders* shaders, Camera* camera) : mesh()
{
  this->shaders = shaders;
  this->camera = camera;
  position = glm::vec3(0);
  scaleVec = glm::vec3(1);
  rotation = glm::vec3(0);
  velocity = glm::vec3(0);

  glGenBuffers(1, &vertexBuffer);
  glGenBuffers(1, &indexBuffer);
}

glm::mat4 Object::getModelMatrix()
{
  glm::quat quaternion(rotation);
  glm::mat4 rotationMatrix(quaternion);

  return glm::translate(glm::mat4(1.0f), position) * rotationMatrix * glm::scale(glm::mat4(1.0f), scaleVec);
}

glm::mat4 Object::getNormalMatrix()
{
  return glm::mat3(glm::transpose(glm::inverse(getModelMatrix())));
}

void Object::update()
{
  position += velocity * Time::deltaTime;
}

void Object::draw()
{
  glm::mat4 mvp = camera->getVp() * getModelMatrix();
  glUniformMatrix4fv(shaders->uniformIds.mvpId, 1, GL_FALSE, &mvp[0][0]);
  glm::mat3 normalMatrix = getNormalMatrix();
  glUniformMatrix3fv(shaders->uniformIds.normalMatrixId, 1, GL_FALSE, &normalMatrix[0][0]);
  
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * sizeof(Vertex), &mesh.vertices[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(unsigned int), &mesh.indices[0], GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, colour));

  glEnableVertexAttribArray(2);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

  glDrawElements(GL_TRIANGLES, mesh.indices.size(), GL_UNSIGNED_INT, nullptr);
}

void Object::translate(glm::vec3 translation)
{
  position += translation;
}

void Object::scale(glm::vec3 scaleVec)
{
  this->scaleVec *= scaleVec;
}

void Object::rotate(glm::vec3 rotation)
{
  this->rotation += rotation;
}

void Object::setVelocity(glm::vec3 velocity)
{
  this->velocity = velocity;
}