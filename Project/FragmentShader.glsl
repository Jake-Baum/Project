#version 330 core

in vec3 fragmentColour;

out vec3 colour;

void main()
{
	float ambientStrength = 0.1;
	vec3 ambient = ambientStrength * vec3(1, 1, 1); //white light

	colour = ambient * fragmentColour;
}