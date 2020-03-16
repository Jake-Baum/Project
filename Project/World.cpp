#include "World.h"

World::World(GLFWwindow *window, Shaders *shaders, Camera *camera) : input(initWindowSize(window))
{
	this->window = window;
	this->shaders = shaders;
	this->camera = camera;
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	currentTime = glfwGetTime();
	prevTime = currentTime;
}

glm::i32vec2 World::initWindowSize(GLFWwindow *window)
{
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	return glm::i32vec2(width, height);
}

Camera* World::getCamera()
{
	return camera;
}


std::vector<Cube> World::getCubes()
{
	return cubes;
}

void World::addCube(Cube cube)
{
	cubes.push_back(cube);
}

void World::start()
{

}

void World::update()
{
	prevTime = currentTime;
	currentTime = glfwGetTime();
	float deltaTime = float(currentTime - prevTime);

	input.handleInput(window, deltaTime, camera);

	camera->update();

	draw();
}

void World::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shaders->programId);

	for (Cube cube : cubes)
	{
		cube.draw();
	}

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glfwSwapBuffers(window);
	glfwPollEvents();
}