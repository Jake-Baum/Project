#include "Mesh.h"

Mesh::Mesh()
{

}

Mesh::Mesh(std::vector<unsigned int> indices, std::vector<Vertex> vertices)
{
	this->indices = indices;
	this->vertices = vertices;
}