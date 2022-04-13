#include <iostream>
#include <string>
#include"include/GLFW/glfw3.h"

int main()
{
	if (!glfwInit())
	{
		std::cout << "error";
	}
	return 0;
}