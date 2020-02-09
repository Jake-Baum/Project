#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

#include "Cube.h"

Cube::Cube(int i)
{
    memcpy(vertexBufferData, baseCubeVertices, sizeof(baseCubeVertices));
    memcpy(colourBufferData, baseColours, sizeof(baseColours));
}

int Cube::getVertexDataLength()
{
    return vertexDataLength;
    //return sizeof(baseCubeVertices) / sizeof(baseCubeVertices[0]);
}
GLfloat* Cube::getVertexBufferData()
{
    return vertexBufferData;
}

GLfloat* Cube::getColourBufferData()
{
    return colourBufferData;
}