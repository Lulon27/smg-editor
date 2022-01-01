#include "RedStar/GLFWOpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "RedStar/Assert.h"

namespace RedStar
{
	GLFWOpenGLContext::GLFWOpenGLContext(RedStar::GLFWWindow* window)
		: m_window(window)
	{
		RS_ASSERT(window, "Window cannot be nullptr");
	}

	bool GLFWOpenGLContext::init()
	{
		RS_ASSERT(!m_initialized, "GLFWOpenGLContext cannot be initialized twice");

		//OpenGL context was created by GLFW.
		//Now only do gladLoadGL().

		glfwMakeContextCurrent(reinterpret_cast<GLFWwindow*>(m_window->getNativeHandle()));
		if (!gladLoadGL())
		{
			return false;
		}
		m_initialized = true;
		return true;
	}

	void GLFWOpenGLContext::swapBuffers()
	{
		RS_ASSERT(m_initialized, "GLFWOpenGLContext must be initialized before calling swapBuffers");
		glfwSwapBuffers(reinterpret_cast<GLFWwindow*>(m_window->getNativeHandle()));
	}

	void GLFWOpenGLContext::setVSync(bool vsync)
	{
		RS_ASSERT(m_initialized, "GLFWOpenGLContext must be initialized before calling setVSync");
		if (vsync)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}
	}
}