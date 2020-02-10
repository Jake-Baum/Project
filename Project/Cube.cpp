#include "Cube.h"

Cube::Cube(int a)
{
    for (int i = 0; i < vertexDataLength; i++)
    {
        vertexBufferData.push_back(baseCubeVertices[i]);
        colourBufferData.push_back(baseColours[i]);
    }
}

int Cube::getVertexDataLength()
{
    return vertexDataLength;
    //return sizeof(baseCubeVertices) / sizeof(baseCubeVertices[0]);
}
std::vector<float> Cube::getVertexBufferData()
{
    return vertexBufferData;
}

std::vector<float> Cube::getColourBufferData()
{
    return colourBufferData;
}