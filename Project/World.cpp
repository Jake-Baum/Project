#include "World.h"
#include "Camera.h"

World::World(GLFWwindow* window, unsigned int programId)
{
	this->window = window;
	this->programId = programId;
}

std::vector<Cube> World::getCubes()
{
	return cubes;
}

void World::addCube(Cube cube)
{
	cubes.push_back(cube);
}

void World::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Camera camera;
	//create matrices
	//glm::mat4 projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	//glm::mat4 view = glm::lookAt(glm::vec3(0, 3, 10), //where camera is in world space
	//	glm::vec3(0, 0, 0), //look towards origin
	//	glm::vec3(0, 1, 0) //camera oriented vertically
	//);

	glm::mat4 vp = camera.getVp();

	glUseProgram(programId);

	for (Cube cube : cubes)
	{
		cube.draw(vp);
	}

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glfwSwapBuffers(window);
	glfwPollEvents();
}