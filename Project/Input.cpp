#include "Input.h"
#include "Camera.h"

Input::Input()
{
	
}

void Input::handleInput(GLFWwindow* window, float deltaTime, Camera& camera)
{
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
}