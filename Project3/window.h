#pragma once

#include <string>
#include"include/GLFW/glfw3.h"


namespace Core
{
	class Window final
	{
	private:
		GLFWwindow* window = nullptr;
		std::string name;
		int width, height;
	public:
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

	private:
		Window(std::string str, int w, int h);
		~Window();
	public:
		static Window& getInstance() { static Window instance("Window", 1280, 720); return instance; }
		void init(std::string str, int w, int h);
		GLFWwindow* getGLFWwindow() const;
	};

}