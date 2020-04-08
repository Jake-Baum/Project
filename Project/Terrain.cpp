#include "Terrain.h"

Terrain::Terrain(Shaders* shaders, Camera* camera, glm::vec3 position, unsigned int width, unsigned int length) : Object(shaders, camera)
{
	this->position = position;
	this->width = width;
	this->length = length;

	Random random;

	float height = 0;

	//add vertices
	float minHeight = 0, maxHeight = 0;
	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{
			height += random.random() - 0.5;
			Vertex vertex;
			vertex.position = glm::vec3(x, height, y);
			vertex.normal = UP;
			mesh.vertices.push_back(vertex);
			if (height > maxHeight)maxHeight = height;
			if (height < minHeight)minHeight = height;
		}
	}

	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{
			float colour;
			colour = mesh.vertices[y * length + x].position.y;
			float norm = (colour - minHeight) / (maxHeight - minHeight);
			mesh.vertices[y * length + x].colour = glm::vec3(norm);
		}
	}

	//add indices
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < width - 1; j++)
		{
			unsigned int bottomLeft = j + i * width;
			unsigned int bottomRight = bottomLeft + 1;
			unsigned int topLeft = bottomLeft + width;
			unsigned int topRight = topLeft + 1;

			mesh.indices.push_back(bottomLeft);
			mesh.indices.push_back(bottomRight);
			mesh.indices.push_back(topLeft);

			mesh.indices.push_back(bottomRight);
			mesh.indices.push_back(topLeft);
			mesh.indices.push_back(topRight);
		}
	}
}