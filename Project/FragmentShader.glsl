#version 330 core

in vec3 fragmentPosition;
in vec3 fragmentColour;
in vec3 fragmentNormal;

out vec3 colour;

void main()
{
	vec3 lightPosition = vec3(10, 10, 4);
	vec3 lightColour = vec3(1, 1, 1); //white light

	//calulate ambient light
	float ambientStrength = 0.1;
	vec3 ambient = ambientStrength * lightColour;

	//calculate diffuse light
	vec3 norm = normalize(fragmentNormal);
	vec3 lightDirection = normalize(lightPosition - fragmentPosition);
	float diff = max(dot(norm, lightDirection), 0.0);
	vec3 diffuse = diff * lightColour;

	colour = (ambient + diffuse) * fragmentColour;
}