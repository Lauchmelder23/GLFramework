#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#ifndef glfInit

void _glfInit()
{
	// Initialize GLFW
	int result = glfwInit();
	if (result == GLFW_FALSE)
		throw std::exception("Failed to initialize GLFW");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

#define glfInit _glfInit

#endif // glfInit

#include "window.hpp"
