#ifndef LIBS_INCLUDED
#define LIBS_INCLUDED
#include "libs.h"
#endif

#include "LoadShader.h"

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
	window = glfwCreateWindow(vidmode->width, vidmode->height, "Window", monitor, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if (!glewInit())
	{
		std::cout << "Could not initialise GLEW.\n";
	}

	//So we can catch key presses
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	
	GLuint vertexArrayId;
	glGenVertexArrays(1, &vertexArrayId);
	glBindVertexArray(vertexArrayId);

	//Compile GLSL program from shaders
	GLuint programId = LoadShaders("VertexShader.glsl", "FragmentShader.glsl");

	GLuint matrixId = glGetUniformLocation(programId, "mvp");

	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	glm::mat4 view = glm::lookAt(glm::vec3(4, 3, 3), //where camera is in world space
		glm::vec3(0, 0, 0), //look towards origin
		glm::vec3(0, 1, 0) //camera oriented vertically
	);
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 mvp = projection * view * model;

	static const GLfloat vertexBufferData[] =
	{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), &vertexBufferData, GL_STATIC_DRAW);


	//Set background colour
	glClearColor(0.1f, 0.1f, 0.3f, 0.2f);

	while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		updateFpsCounter(window);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(programId);

		glUniformMatrix4fv(matrixId, 1, GL_FALSE, &mvp[0][0]);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteBuffers(1, &vertexBuffer);
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