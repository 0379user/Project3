#pragma once

#include <string>
#include <functional>
#include"include/GLFW/glfw3.h"
#include "event.h"

namespace Core
{
	class Window final
	{
	private:
		GLFWwindow* window = nullptr;
		std::function<void(Event&)> fnCallback;
		std::string name;
		int width, height;
	public:
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
	private:
		Window(const std::string& str, int w, int h);
		~Window();
	public:
		static Window& getInstance() { static Window instance("Window", 1280, 720); return instance; }
		void init(const std::string &str, int w, int h);
		GLFWwindow* getGLFWwindow() const;
	public:
		void setfnCallback(const std::function<void(Event&)> & fn) { fnCallback = fn; }
	public:	
		static void mouseMovedCallback(GLFWwindow* window, double x, double y);
		static void mouseScrollCallback(GLFWwindow* window, double x, double y);
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void windowResizeCallback(GLFWwindow* window, int wight, int height);
		static void windowClosedCallback(GLFWwindow* window);
	};

}