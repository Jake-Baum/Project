#include "Cube.h"

Cube::Cube()
{
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            vertexBufferData.push_back(baseCubeVertices[i][j]);
            colourBufferData.push_back(baseColours[i][j]);
        }
    }
    for (int i = 0; i < numIndices; i++)
    {
        indexBufferData.push_back(baseIndices[i]);
    }

    position = glm::vec3(3.0f, 1.0f, 1.0f);
}

Cube::Cube(glm::vec3 position)
{
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            vertexBufferData.push_back(baseCubeVertices[i][j]);
            colourBufferData.push_back(baseColours[i][j]);
        }
    }
    for (int i = 0; i < numIndices; i++)
    {
        indexBufferData.push_back(baseIndices[i]);
    }

    this->position = position;

    mvpId = 1;

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertexBufferData.size() * sizeof(float), &vertexBufferData[0], GL_STATIC_DRAW);

    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBufferData.size() * sizeof(unsigned int), &indexBufferData[0], GL_STATIC_DRAW);
    
    glGenBuffers(1, &colourBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
    glBufferData(GL_ARRAY_BUFFER, colourBufferData.size() * sizeof(float), &colourBufferData[0], GL_STATIC_DRAW);
}

//Cube::~Cube()
//{
//  glDeleteBuffers(1, &vertexBuffer);
//  glDeleteBuffers(1, &indexBuffer);
//  glDeleteBuffers(1, &colourBuffer);
//}

std::vector<float> Cube::getVertexBufferData()
{
    return vertexBufferData;
}

std::vector<unsigned int> Cube::getIndexBufferData()
{
    return indexBufferData;
}

std::vector<float> Cube::getColourBufferData()
{
    return colourBufferData;
}

glm::mat4 Cube::getModelMatrix()
{
    return glm::translate(glm::mat4(1.0f), position);
}

void Cube::setMvpId(unsigned int id)
{
  mvpId = id;
}

void Cube::draw(glm::mat4 vp)
{
  glm::mat4 mvp = vp * getModelMatrix();
  glUniformMatrix4fv(mvpId, 1, GL_FALSE, &mvp[0][0]);

  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

  glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, nullptr);
}