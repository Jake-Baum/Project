#include "World.h"

World::World(GLFWwindow* window, unsigned int programId, Camera camera)
{
	this->window = window;
	this->programId = programId;
	this->camera = camera;
}

std::vector<Cube> World::getCubes()
{
	return cubes;
}

void World::addCube(Cube cube)
{
	cubes.push_back(cube);
}

void World::update()
{
	prevTime = currentTime;
	currentTime = glfwGetTime();
	float deltaTime = float(currentTime - prevTime);

	glm::vec3 velocity(0);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		velocity.z -= camera.getSpeed();
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		velocity.z += camera.getSpeed();
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		velocity.x -= camera.getSpeed();
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		velocity.x += camera.getSpeed();
	}
	camera.translate(deltaTime * velocity);

	draw();
}

void World::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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