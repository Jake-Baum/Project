#version 330 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColour;
layout(location = 2) in vec3 vertexNormal;

out vec3 fragmentPosition;
out vec3 fragmentColour;
out vec3 fragmentNormal;

uniform mat4 mvp;
uniform mat3 normalMatrix;

void main()
{
	gl_Position = mvp * vec4(vertexPosition, 1);
	fragmentPosition = vertexPosition;
	fragmentColour = vertexColour;
	fragmentNormal = normalMatrix * vertexNormal;
}