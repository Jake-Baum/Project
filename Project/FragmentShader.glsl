#version 330 core

in vec3 fragmentPosition;
in vec3 fragmentColour;
in vec3 fragmentNormal;

uniform vec3 cameraPosition;

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

	//calculate specular light
	float strength = 0.5;
	vec3 viewDirection = normalize(cameraPosition - fragmentPosition);
	vec3 reflectionDirection = reflect(lightDirection, fragmentNormal);
	vec3 specular = pow(max(dot(viewDirection, reflectionDirection), 0.0), 32) * strength * lightColour;//32 is 'shininess of an object'

	colour = (ambient + diffuse + specular) * fragmentColour;
}