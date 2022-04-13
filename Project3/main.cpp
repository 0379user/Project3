#include <iostream>
#include <string>
#include"include/GLFW/glfw3.h"
#include "window.h"

int main()
{
	Core::Window& window = Core::Window::getInstance();

	while (true)
	{
		glfwPollEvents();
		glfwSwapBuffers(window.getGLFWwindow());
	}

	return 0;
}