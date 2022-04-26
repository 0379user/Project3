#include <iostream>
#include <string>
#include <assert.h>
#include"include/GLFW/glfw3.h"

#include "window.h"
#include "mouseevent.h"

//#include "system.h"
#include "objectmodel.h"

#pragma warning( disable : 4098 )

int main()
{
#if 0

	Core::Window& window = Core::Window::getInstance();

	while (!glfwWindowShouldClose(window.getGLFWwindow()))
	{
		glfwPollEvents();
		glfwSwapBuffers(window.getGLFWwindow());
	}

#endif
	

	//assert(Core::Util::isLittleEndian());
#if 1
	std::vector<int16_t> vec{ 1,2,3,4 };
	Core::Root* r = Core::Array::createArray("ARRAY", Core::Type::I16, vec);
	std::string str = "dddd";
	Core::Root* f = Core::Array::createString("STRING", Core::Type::I8, str);

	Core::Object Test("TEST");

	Test.addEntitie(r);
	Test.addEntitie(f);

	Core::Util::retriveNsave(&Test);

#endif


	return 0;
}