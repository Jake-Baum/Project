#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

#include "LoadShader.h"
#include "World.h"
#include "Cube.h"
#include "Plane.h"
#include "Terrain.h"

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
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//Set background colour
	glClearColor(0.1f, 0.1f, 0.3f, 0.2f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	GLuint vertexArrayId;
	glGenVertexArrays(1, &vertexArrayId);
	glBindVertexArray(vertexArrayId);

	//Compile GLSL program from shaders
	Shaders shaders;

	shaders.programId = LoadShaders("VertexShader.glsl", "FragmentShader.glsl");

	shaders.uniformIds.mvpId = glGetUniformLocation(shaders.programId, "mvp");
	shaders.uniformIds.cameraPositionId = glGetUniformLocation(shaders.programId, "cameraPosition");
	shaders.uniformIds.normalMatrixId = glGetUniformLocation(shaders.programId, "normalMatrix");


	Camera camera(&shaders);
	World world(window, &shaders, &camera);

	std::vector<Cube> cubes =
	{
		Cube(&shaders, &camera, glm::vec3(4.0f, 0.0f, 0.0f)), 
		Cube(&shaders, &camera, glm::vec3(-4.0f, 0.0f, 0.0f)), 
		Cube(&shaders, &camera, glm::vec3(0.0f, 0.0f, -4.0f)), 
		Cube(&shaders, &camera, glm::vec3(0.0f, 2.0, -4.0))
	};

	cubes[0].scale(glm::vec3(0.5, 0.5, 0.5));
	cubes[0].rotate(glm::vec3(0, 30, 0));
	cubes[1].setVelocity(glm::vec3(0, 0, 1));

	Plane plane(&shaders, &camera, glm::vec3(0, 0, 0));

	Terrain terrain(&shaders, &camera, glm::vec3(0, 0, 0), 100, 100);
	
	for (Cube& cube: cubes)
	{
		world.addObject(&cube);
	}
	
	world.addObject(&plane);
	world.addObject(&terrain);
	
	int numberOfFrames = 0;
	double startTime = glfwGetTime();
	while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
 		Time::update();
 		updateFpsCounter(window);
		world.update();
		numberOfFrames++;
	}

	std::cout  << "Average time per frame: " << (glfwGetTime() - startTime) / numberOfFrames << "s\n";

	glDeleteProgram(shaders.programId);
	glDeleteVertexArrays(1, &vertexArrayId);

	glfwTerminate();

	return 0;
}

void updateFpsCounter(GLFWwindow* window)
{
	static int frameCount;
	static float total;

	total += Time::deltaTime;
	frameCount++;

	if (total > 0.5f)
	{
		char fpsString[128];
		sprintf_s(fpsString, "fps: %.2f", frameCount / total);
		glfwSetWindowTitle(window, fpsString);
		frameCount = 0;
		total = 0;
	}
	return;
}