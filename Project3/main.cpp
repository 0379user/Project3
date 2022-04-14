#include <iostream>
#include <string>
#include"include/GLFW/glfw3.h"
#include "window.h"
#include "system.h"
#include "mouseevent.h"


int main()
{
#if 1

	Core::Window& window = Core::Window::getInstance();

	while (!glfwWindowShouldClose(window.getGLFWwindow()))
	{
		glfwPollEvents();
		glfwSwapBuffers(window.getGLFWwindow());
	}

#endif
	//Core::System system("sys");
	//Core::Event* e = new Core::MouseScrolledEvent(1);
	//system.addEvent(e);
	return 0;
}