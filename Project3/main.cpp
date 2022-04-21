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
	

	assert(Core::Util::isLittleEndian());
#if 0
	std::vector<int16_t> vec{ 1,2,3,4 };
	Core::Root* r = Core::Array::createArray("ARRAY", Core::Type::I16, vec);
	std::string str = "dddd";
	Core::Root* f = Core::Array::createString("STRING", Core::Type::I8, str);

	Core::Object Test("TEST");

	Test.addEntitie(r);
	Test.addEntitie(f);

	Core::Util::retriveNsave(&Test);

#endif

	Core::System system("SyS_serialization");
	Core::Event* e = new Core::MouseButtonPressedEvent(1);
	system.s
	return 0;
}