#pragma once

#include "RedStar/Window.h"

#include <memory>

struct GLFWwindow;

namespace RedStar
{
	/**
	 * @brief A window that uses GLFW.
	 */
	class GLFWWindow : public Window
	{
	public:

		/**
		 * @brief Creates a window using GLFW.
		 * 
		 * Creates a window using GLFW. Multiple windows can be created.
		 * GLFW will be initialized when the first window is created and terminated when the
		 * last window is destructed
		 * If an error occurs during initialization the error state will be set to true.
		 * This can be checked with getError() and will be replaced with exceptions in
		 * the future.
		 * 
		 * @param[in] props			WindowProps to tell how the window should be created
		 * @param[in] contextApi	which API should be used for context creation, for example OpenGL
		 */
		GLFWWindow(const WindowProps& props, GraphicsContext::API contextAPI);
		GLFWWindow(const GLFWWindow&) = delete;
		~GLFWWindow();

		void onUpdate() override;

		void* getNativeHandle() const override
		{
			return m_windowHandle;
		}

		void show() override;
		void hide() override;
		bool isVisible() override;

		void setVSync(bool vsync) override;
		bool isVSyncEnabled() override;

		GraphicsContext* getGraphicsContext() override;

		bool getError() override;

	private:
		GLFWwindow* m_windowHandle = nullptr;
		bool m_vsyncEnabled = false;
		std::unique_ptr<GraphicsContext> m_context = nullptr;
		bool m_error = false;
	};
}