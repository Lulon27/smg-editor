#include "RedStar/GLFWWindow.h"
#include "RedStar/Assert.h"

#include <GLFW/glfw3.h>

#include "RedStar/RedStarApp.h"

namespace RedStar
{
	static size_t windowCount = 0;
	static bool glfwIsInited = false;
	static bool glfwSetup = false;
	static Logger glfwLogger = Logger::create("GLFW");

	static void errorCallback(int error, const char* description)
	{
		glfwLogger.error(description);
	}

	GLFWWindow::GLFWWindow(const WindowProps& props)
	{
		//One time setup for GLFW independent of glfwInit
		if (!glfwSetup)
		{
			glfwSetErrorCallback(errorCallback);
			glfwSetup = true;
		}

		//Always increment window count, even if window fails to create
		//so that glfw can be terminated correctly in destructor.

		//Even if glfw fails to init. Otherwise the destructor would decrement the zero value
		//and window count is unsigned.
		++windowCount;

		if (!glfwIsInited) //Always try to init if it hasn't worked yet.
		{
			if (!(glfwIsInited = glfwInit()))
			{
				RS_ASSERT(false, "Failed to init GLFW");
				return;
			}
		}
		glfwWindowHint(GLFW_MAXIMIZED, props.maximized);
		glfwWindowHint(GLFW_VISIBLE, props.visible);

		//Dont create context for now
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		m_windowHandle = glfwCreateWindow(props.width, props.height, props.title, nullptr, nullptr);
		RS_ASSERT(m_windowHandle, "Failed to create GLFW window");

		//VSync only works after context creation
		//setVSync(props.vsync);
	}

	GLFWWindow::~GLFWWindow()
	{
		if (m_windowHandle) // In case the window failed to create
		{
			glfwDestroyWindow(m_windowHandle);
		}

		--windowCount;
		if (windowCount == 0 && glfwIsInited)
		{
			glfwTerminate();
		}
	}

	void GLFWWindow::onUpdate()
	{
		RS_ASSERT(m_windowHandle, "Cannot update an uninitialized window!");
		glfwPollEvents();
		if (glfwWindowShouldClose(m_windowHandle))
		{
			glfwSetWindowShouldClose(m_windowHandle, false);
			hide();
		}
	}

	void GLFWWindow::show()
	{
		glfwShowWindow(m_windowHandle);
	}

	void GLFWWindow::hide()
	{
		glfwHideWindow(m_windowHandle);
	}

	bool GLFWWindow::isVisible()
	{
		return glfwGetWindowAttrib(m_windowHandle, GLFW_VISIBLE);
	}

	void GLFWWindow::setVSync(bool vsync)
	{
		if (vsync)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}
	}

	bool GLFWWindow::isVSyncEnabled()
	{
		return m_vsyncEnabled;
	}
}