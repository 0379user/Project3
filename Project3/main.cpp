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

	assert(Core::Util::isLittleEndian());
	int16_t f = 55;

	Core::Root* r = Core::Primitive::create("primiteve", Core::Type::I16, f);
	Core::Util::retriveNsave(r);

	/*std::vector<int64_t> data{ 1,2,3,4 };
	Core::Array* r = Core::Array::createArray("arr", Core::Type::I64, data);
	Core::Util::retriveNsave(r);

	std::string str="name";
	Core::Root* rt = Core::Array::createString("string", Core::Type::I8, str);
	Core::Util::retriveNsave(rt);*/
	//std::cout << sizeof(*rt);
	return 0;
}