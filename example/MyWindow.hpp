#include "glf.hpp"

using namespace glf;

class MyWindow :
	public IWindow
{
public:
	MyWindow() :
		IWindow()
	{
		Create(800, 600, "Example Window");

		glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);
	}

private:
	static void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
};