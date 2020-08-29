#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace glf
{
#define USER_CALLBACK virtual void
#define LIB_CALLBACK static void

	class IWindow
	{
	public:
		void Create(int width, int height, const char* title, bool fullscreen = false, GLFWwindow* share = nullptr);
		void Close() noexcept;

		int ShouldClose();

		void Display();
		void PollEvents();	// TODO: needed?

	protected:
		IWindow();

	protected:
		GLFWwindow* window;

		GLFWmonitor* monitor;
		GLFWwindow* share;
	};
}