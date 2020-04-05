#pragma once

#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

#include "Camera.h"
#include "Mesh.h"

class Object
{
protected:
	Shaders *shaders;
	Camera *camera;

	glm::vec3 position;
	glm::vec3 scaleVec;
	glm::vec3 rotation;

	glm::vec3 velocity;

	Mesh mesh;

public:
	Object(Shaders *, Camera *);
	
	virtual glm::mat4 getModelMatrix();
	virtual glm::mat4 getNormalMatrix();

	virtual void update();
	virtual void draw();
	virtual void translate(glm::vec3);
	virtual void scale(glm::vec3);
	virtual void rotate(glm::vec3);

	virtual void setVelocity(glm::vec3);
};