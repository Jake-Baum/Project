#include "Cube.h"

Cube::Cube(int a)
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