#pragma once

#include "GraphicsContext.h"
#include "GLFWWindow.h"

namespace RedStar
{
	class GLFWOpenGLContext : public GraphicsContext
	{
	public:
		GLFWOpenGLContext(RedStar::GLFWWindow* window);

		bool init() override;
		void swapBuffers() override;
		void setVSync(bool vsync) override;
	private:
		RedStar::GLFWWindow* m_window;
		bool m_initialized = false;
	};
}