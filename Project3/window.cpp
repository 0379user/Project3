#include "window.h"

namespace Core
{
	Window::Window(std::string str, int w, int h)
	{
		init(str, w, h);
	}


	Window::~Window()
	{
		glfwWindowShouldClose(window);
	}

	void Window::init(std::string str, int w, int h)
	{
		name = str;
		width = w;
		height = h;

		if (!glfwInit())
		{
			_asm {int 3}
		}
		window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
		if (!window)
		{
			_asm {int 3}
		}
		glfwMakeContextCurrent(window);
	}

	GLFWwindow* Window::getGLFWwindow() const
	{
		return window;
	}
}