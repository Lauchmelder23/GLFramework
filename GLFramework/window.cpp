#include "window.hpp"

#include <exception>

namespace glf
{
	IWindow::IWindow() :
		window(nullptr), monitor(nullptr), share(nullptr)
	{

	}

	void IWindow::Create(int width, int height, const char* title, bool fullscreen /*= false*/, GLFWwindow* share /*= nullptr*/)
	{
		// Create window
		if (window == nullptr)
		{
			if (fullscreen)
				true;	// TODO: Implement monitor stuff

			this->share = share;
			window = glfwCreateWindow(width, height, title, monitor, share);
			if (window == nullptr)
			{
				throw std::exception("Failed to create GLFWwindow");
			}

			glfwMakeContextCurrent(window);

			// Initialize GLAD
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
				throw std::exception("Failed to initialize GLAD");

			// Set viewport
			glViewport(0, 0, width, height);
		}
	}

	void IWindow::Close() noexcept
	{
		glfwDestroyWindow(window);
	}

	int IWindow::ShouldClose()
	{
		return glfwWindowShouldClose(window);
	}

	void IWindow::Display()
	{
		glfwSwapBuffers(window);
	}

	void IWindow::PollEvents()
	{
		glfwPollEvents();
	}

}