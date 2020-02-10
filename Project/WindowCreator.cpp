#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

#include "LoadShader.h"
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

	GLuint matrixId = glGetUniformLocation(programId, "mvp");

	Cube cubes[] =
	{
		Cube(glm::vec3(4.0f, 0.0f, 0.0f)), Cube(glm::vec3(-4.0f, 0.0f, 0.0f))
	};

	glm::mat4 mvps[2];

	//create matrices
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	glm::mat4 view = glm::lookAt(glm::vec3(0, 5, 10), //where camera is in world space
		glm::vec3(0, 0, 0), //look towards origin
		glm::vec3(0, 1, 0) //camera oriented vertically
	);
	mvps[0] = projection * view * cubes[0].getModelMatrix();
	mvps[1] = projection * view * cubes[1].getModelMatrix();

	

	std::vector<float> vertexBufferData = cubes[0].getVertexBufferData();
	unsigned int vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexBufferData.size() * sizeof(float), &vertexBufferData[0], GL_STATIC_DRAW);
	std::cout << vertexBufferData.size() << " 24\n";


	std::vector<unsigned int> indexBufferData = cubes[0].getIndexBufferData();
	unsigned int indexBuffer;
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBufferData.size() * sizeof(unsigned int), &indexBufferData[0], GL_STATIC_DRAW);
	std::cout << indexBufferData.size() << " 36\n";

	std::vector<float> colourBufferData = cubes[0].getColourBufferData();
	GLuint colourBuffer;
	glGenBuffers(1, &colourBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
	glBufferData(GL_ARRAY_BUFFER, colourBufferData.size() * sizeof(float), &colourBufferData[0], GL_STATIC_DRAW);
	std::cout << vertexBufferData.size() << " 24\n";


	while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		updateFpsCounter(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(programId);

		glUniformMatrix4fv(matrixId, 1, GL_FALSE, &mvps[0][0][0]);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glDrawElements(GL_TRIANGLES, cubes[0].numIndices, GL_UNSIGNED_INT, nullptr);
		
		glUniformMatrix4fv(matrixId, 1, GL_FALSE, &mvps[1][0][0]);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glDrawElements(GL_TRIANGLES, cubes[1].numIndices, GL_UNSIGNED_INT, nullptr);
		
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteBuffers(1, &vertexBuffer);
	//glDeleteBuffers(1, &colourBuffer);
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