#include <iostream>
#include <string>
#include"include/GLFW/glfw3.h"
#include "window.h"
#include "system.h"
#include "mouseevent.h"
#include "objectmodel.h"
#include <assert.h>

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
	//Core::System system("sys");
	//Core::Event* e = new Core::MouseScrolledEvent(1);
	//system.addEvent(e);

	//assert(Core::Util::isLittleEndian()); 

	int foo = 5;
	Core::Root* r = Core::Primitive::create("int32", Core::Type::I32, foo);
	Core::Util::retriveNsave(r);
	return 0;
}