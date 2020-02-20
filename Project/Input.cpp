#include "Input.h"
#include "Camera.h"

Input::Input()
{

}

Input::Input(glm::i32vec2 windowSize)
{
	this->windowSize = windowSize;
	mouseCoords;
}

void Input::handleInput(GLFWwindow* window, float deltaTime, Camera& camera)
{
	glfwGetCursorPos(window, &mouseCoords.x, &mouseCoords.y);
	//set cursor position back to centre of screen
	glfwSetCursorPos(window, windowSize.x / 2, windowSize.y / 2);
	glm::vec2 angle(0);
	angle.x = mouseSpeed * float(windowSize.x / 2 - mouseCoords.x) * deltaTime;
	angle.y = mouseSpeed * float(windowSize.y / 2 - mouseCoords.y) * deltaTime;
	

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
	camera.rotate(angle);
}

glm::f64vec2 Input::getMouseCoords()
{
	return mouseCoords;
}