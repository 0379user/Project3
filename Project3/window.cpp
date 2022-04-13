#include "window.h"
#include "mouseevent.h"
#include "keyboardevent.h"
#include <iostream>
#include "windoweven.h"
namespace Core
{
	Window::Window(const std::string& str, int w, int h)
	{
		init(str, w, h);
		setfnCallback([&](Event& e)
			{
				if (e.getType() == Event::EventType::WINDOW_CLOSE_EVENT)
				{
					glfwSetWindowShouldClose(window, GL_TRUE);
				}
				std::cout << e.format() << std::endl;
			});
	}




	void Window::init(const std::string& str, int w, int h)
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
		glfwSetWindowUserPointer(window, this);
		glfwSetCursorPosCallback(window, mouseMovedCallback);
		glfwSetScrollCallback(window, mouseScrollCallback);
		glfwSetMouseButtonCallback(window, mouseButtonCallback);
		glfwSetKeyCallback(window, keyCallback);
		glfwSetWindowSizeCallback(window, windowResizeCallback);
		glfwSetWindowCloseCallback(window, windowClosedCallback);
	}

	GLFWwindow* Window::getGLFWwindow() const
	{
		return window;
	}


	void Window::mouseMovedCallback(GLFWwindow* window, double x, double y)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		MouseMovedEvent e(x, y);
		handle.fnCallback(e);
	}
	void Window::mouseScrollCallback(GLFWwindow* window, double x, double y)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		MouseScrolledEvent e(y);
		handle.fnCallback(e);
	}
	void Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		if (action == GLFW_PRESS)
		{
			MouseButtonPressedEvent e(button);
			handle.fnCallback(e);
		}
		else
		{
			MouseButtonReleasedEvent e(button);
			handle.fnCallback(e);
		}


	}

	void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		if (action == GLFW_PRESS)
		{
			KeyPressedEvent e(key);
			handle.fnCallback(e);
		}
		else if (action == GLFW_RELEASE)
		{
			KeyReleasedEvent e(key);
			handle.fnCallback(e);
		}
	}

	  void Window::windowResizeCallback(GLFWwindow* window, int wight, int height) 
	  {
		  auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		  WindowReasizedEvent e(wight, height);
		  handle.height = height;
		  handle.width = wight;
		  handle.fnCallback(e);
	  }
	    void Window::windowClosedCallback(GLFWwindow* window)
		{
			auto& handle = *(Window*)glfwGetWindowUserPointer(window);
			WindowClosedEvent e;
			handle.fnCallback(e);
		}


	  Window::~Window()
	  {
		  glfwWindowShouldClose(window);
	  }
}