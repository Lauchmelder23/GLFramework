#include "glf.hpp"
#include "MyWindow.hpp"

int main(int argc, char** argv)
{
	MyWindow* window = nullptr;
	try {
		glfInit();
		window = new MyWindow;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	while (!window->ShouldClose())
	{
		glfwPollEvents();
		window->Display();
	}

	window->Close();
	glfwTerminate();

	return 0;
}