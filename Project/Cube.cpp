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
}

std::vector<float> Cube::getVertexBufferData()
{
    return vertexBufferData;
}

std::vector<float> Cube::getColourBufferData()
{
    return colourBufferData;
}