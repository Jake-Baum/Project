#version 330 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColour;
layout(location = 2) in vec3 vertexNormal;

out vec3 fragmentColour;

uniform mat4 mvp;

void main()
{
	gl_Position = mvp * vec4(vertexPosition, 1);
	fragmentColour = vertexColour;
}