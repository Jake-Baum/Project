#pragma once

#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

#include "Mesh.h"

class Cube
{
public:
    static const unsigned int numVertices = 8;
    static const unsigned int numIndices = 36;

private:
    static constexpr GLfloat vertices[][3] =
    {
        {-1.0f,-1.0f,-1.0f},//0
        {-1.0f,-1.0f, 1.0f},//1
        {-1.0f, 1.0f, 1.0f },//2
        {1.0f, 1.0f, -1.0f},//3
        {-1.0f, 1.0f,-1.0f},//4
        {1.0f,-1.0f, 1.0f},//5
        {1.0f,-1.0f,-1.0f},//6
        {1.0f, 1.0f, 1.0f}//7
    };

    static constexpr unsigned int indices[] =
    {
        0,1,2,
        3,0,4,
        5,0,6,
        3,6,0,
        0,2,4,
        5,1,0,
        2,1,5,
        7,6,3,
        6,7,5,
        7,3,4,
        7,4,2,
        7,2,5
    };


    static constexpr GLfloat colours[][3] = 
    {
        {0.583f,  0.771f,  0.014f},
        {0.609f,  0.115f,  0.436f},
        {0.327f,  0.483f,  0.844f},
        {0.822f,  0.569f,  0.201f},
        {0.435f,  0.602f,  0.223f},
        {0.310f,  0.747f,  0.185f},
        {0.597f,  0.770f,  0.761f},
        {0.559f,  0.436f,  0.730f}
    };

    Mesh mesh;

public:
    Cube(Shaders *, Camera *, glm::vec3);
    void draw();
};