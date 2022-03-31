#include "RedStar/GLFWWindow.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "RedStar/Assert.h"
#include "RedStar/GLFWOpenGLContext.h"
#include "RedStar/Events/WindowEvent.h"
#include "RedStar/Events/KeyEvent.h"
#include "RedStar/Events/MouseEvent.h"
#include "RedStar/Events/CharTypedEvent.h"

namespace RedStar
{
#define GLFW_WINDOW_PTR(glfwWindow) ((GLFWWindow*)glfwGetWindowUserPointer(glfwWindow))

#define EVENT_CALLBACK(eventName, glfwWindow, ...)								\
	GLFWWindow* myWin = (GLFWWindow*)glfwGetWindowUserPointer(glfwWindow);		\
	if (myWin->m_eventCallbacks) {												\
		myWin->m_eventCallbacks->pushEvent<eventName>(myWin, ##__VA_ARGS__);	\
	}																			\

	static size_t windowCount = 0;
	static bool glfwIsInited = false;
	static bool glfwSetup = false;
	static Logger glfwLogger = Logger::create("GLFW", Logger::Level::Trace);

	static void errorCallback(int error, const char* description)
	{
		glfwLogger.error(description);
	}

	static void doGlfwSetup()
	{
		glfwLogger.debug(glfwGetVersionString());
		glfwSetErrorCallback(errorCallback);
		glfwSetup = true;
		glfwLogger.debug("Initial setup done!");
	}

	GLFWWindow::GLFWWindow(const WindowProps& props, GraphicsContext::API contextAPI)
	{
		//One time setup for GLFW independent of glfwInit
		if (!glfwSetup)
		{
			doGlfwSetup();
		}

		//Always increment window count, even if window fails to create
		//so that glfw can be terminated correctly in destructor.

		//Even if glfw fails to init. Otherwise the destructor would decrement the zero value
		//and window count is unsigned.
		++windowCount;

		if (!glfwIsInited) //Always try to init even if it hasn't worked yet.
		{
			glfwLogger.debug("Initializing...");
			if (!(glfwIsInited = glfwInit()))
			{
				RS_ASSERT(false, "Failed to init GLFW");
				return;
			}
			glfwLogger.debug("Done!");
		}
		glfwWindowHint(GLFW_MAXIMIZED, props.maximized);
		glfwWindowHint(GLFW_VISIBLE, props.visible);

		glfwLogger.debug("Using context API: {}", contextAPI);
		if (contextAPI == GraphicsContext::API::OpenGL)
		{
			//We only want OpenGL 3.2+
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

			m_context = std::make_unique<GLFWOpenGLContext>(this);
		}
		else
		{
			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
			//m_context = std::make_unique<SomeOtherContext>(this);
			RS_ASSERT(false, "Only OpenGL is supported for GLFW window");
			return;
		}

		RS_ASSERT(m_context, "m_context cannot be nullptr");

		//---------------------------------------//
		// Init contexts other than OpenGL here. //
		//---------------------------------------//

		glfwLogger.debug("Creating window... [width={}, height={}]", props.width, props.height);
		m_windowHandle = glfwCreateWindow(props.width, props.height, props.title, nullptr, nullptr);

		if (!m_windowHandle)
		{
			glfwLogger.critical("Failed to create window [width={}, height={}]", props.width, props.height);
			m_error = true;
			return;
		}

		//Call context init after glfwCreateWindow because
		//GLFW creates an OpenGL context
		if (contextAPI == GraphicsContext::API::OpenGL)
		{
			glfwLogger.debug("Loading OpenGL context...");
			if (!m_context->init())
			{
				glfwLogger.critical("Failed to load OpenGL context");
				m_error = true;
				return;
			}
			glfwLogger.debug("Done!");
		}

		//VSync only works after context creation
		setVSync(props.vsync);

		glfwSetWindowUserPointer(m_windowHandle, this);

		glfwSetWindowCloseCallback(m_windowHandle, [](GLFWwindow* window)
		{
			EVENT_CALLBACK(WindowCloseEvent, window);
		});

		glfwSetWindowSizeCallback(m_windowHandle, [](GLFWwindow* window, int width, int height)
		{
			EVENT_CALLBACK(WindowResizeEvent, window, width, height);
		});

		glfwSetKeyCallback(m_windowHandle, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (action == GLFW_PRESS)
			{
				EVENT_CALLBACK(KeyPressedEvent, window, Input::keyFromGLFW(key), Input::modsFromGLFW(mods));
			}
			else if (action == GLFW_RELEASE)
			{
				EVENT_CALLBACK(KeyReleasedEvent, window, Input::keyFromGLFW(key), Input::modsFromGLFW(mods));
			}
			else if (action == GLFW_REPEAT)
			{
				EVENT_CALLBACK(KeyTypedEvent, window, Input::keyFromGLFW(key), Input::modsFromGLFW(mods));
			}
		});

		glfwSetCharCallback(m_windowHandle, [](GLFWwindow* window, unsigned int codepoint)
		{
			EVENT_CALLBACK(CharTypedEvent, window, codepoint);
		});

		glfwSetMouseButtonCallback(m_windowHandle, [](GLFWwindow* window, int button, int action, int mods)
		{
			if (action == GLFW_PRESS)
			{
				EVENT_CALLBACK(MouseButtonPressedEvent, window, Input::mouseButtonFromGLFW(button), Input::modsFromGLFW(mods));
			}
			else if (action == GLFW_RELEASE)
			{
				EVENT_CALLBACK(MouseButtonReleasedEvent, window, Input::mouseButtonFromGLFW(button), Input::modsFromGLFW(mods));
			}
		});

		glfwSetScrollCallback(m_windowHandle, [](GLFWwindow* window, double xoffset, double yoffset)
		{
			EVENT_CALLBACK(MouseScrolledEvent, window, xoffset, yoffset);
		});

		glfwSetCursorPosCallback(m_windowHandle, [](GLFWwindow* window, double xpos, double ypos)
		{
			EVENT_CALLBACK(MouseMovedEvent, window, xpos, ypos);
		});
	}

	GLFWWindow::~GLFWWindow()
	{
		if (m_windowHandle) // In case the window failed to create
		{
			glfwDestroyWindow(m_windowHandle);
			glfwLogger.debug("Destroyed window [m_windowHandle={}]", (void*)m_windowHandle);
		}

		--windowCount;
		if (windowCount == 0 && glfwIsInited)
		{
			glfwTerminate();
			glfwLogger.debug("Terminated (all windows closed)");
		}
	}

	void GLFWWindow::onUpdate()
	{
		if (m_error)
		{
			return;
		}

		RS_ASSERT(m_windowHandle, "Cannot update an uninitialized window!");

		glfwPollEvents();
		if (glfwWindowShouldClose(m_windowHandle))
		{
			glfwSetWindowShouldClose(m_windowHandle, false);
			hide();
		}

		/* 
		 * Don't swap buffers here;
		 * This is done in the main loop after
		 * layer stack updates etc.
		 */ 
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
		RS_ASSERT(m_context, "m_context cannot be nullptr");
		m_context->setVSync(vsync);
	}

	bool GLFWWindow::isVSyncEnabled()
	{
		return m_vsyncEnabled;
	}

	GraphicsContext* GLFWWindow::getGraphicsContext()
	{
		return m_context.get();
	}

	bool GLFWWindow::getError()
	{
		return m_error;
	}
}