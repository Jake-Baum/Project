#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

#include "LoadShader.h"
#include "World.h"
#include "Cube.h"

void updateFpsCounter(GLFWwindow*);

int main()
{
	GLFWwindow* window;

	//initialise library
	if (!glfwInit())
	{
		std::cout << "Could not initialise GLFW.\n";
		return 1;
	}

	//create window and OpenGL context
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
	
	bool fullScreen = false;
	int screenWidth = vidmode->width;
	int screenHeight = vidmode->height;

	if (!fullScreen)
	{
		monitor = NULL;
		screenWidth = 640;
		screenHeight = 480;
	}

	window = glfwCreateWindow(screenWidth, screenHeight, "Window", monitor, NULL);
	if (!window)
	{
		std::cout << "Could not create window.\n";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		std::cout << "Could not initialise GLEW.\n";
		std::cout << glewGetErrorString(err) << "\n";
		glfwTerminate();
		return -1;
	}

	//So we can catch key presses
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	//Set background colour
	glClearColor(0.1f, 0.1f, 0.3f, 0.2f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	GLuint vertexArrayId;
	glGenVertexArrays(1, &vertexArrayId);
	glBindVertexArray(vertexArrayId);

	//Compile GLSL program from shaders
	GLuint programId = LoadShaders("VertexShader.glsl", "FragmentShader.glsl");

	unsigned int mvpId = glGetUniformLocation(programId, "mvp");

	World world(window, programId);

	std::vector<Cube> cubes =
	{
		Cube(glm::vec3(4.0f, 0.0f, 0.0f)), Cube(glm::vec3(-4.0f, 0.0f, 0.0f)), Cube(glm::vec3(0.0f, 0.0f, -4.0f)), Cube(glm::vec3(0.0f, 2.0, -4.0))
	};

	for (Cube& cube: cubes)
	{
		cube.setMvpId(mvpId);
		world.addCube(cube);
	}

	while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		updateFpsCounter(window);
		world.draw();
	}

	glDeleteProgram(programId);
	glDeleteVertexArrays(1, &vertexArrayId);

	glfwTerminate();

	return 0;
}

void updateFpsCounter(GLFWwindow* window)
{
	static double previousSeconds = glfwGetTime();
	static int frameCount;
	double currentSeconds = glfwGetTime();
	double elapsedSeconds = currentSeconds - previousSeconds;
	if (elapsedSeconds > 0.25f)
	{
		previousSeconds = currentSeconds;
		double fps = (double)frameCount / elapsedSeconds;
		char fpsString[128];
		sprintf_s(fpsString, "fps: %.2f", fps);
		glfwSetWindowTitle(window, fpsString);
		frameCount = 0;
	}
	frameCount++;
}