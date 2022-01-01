#pragma once

#include "RedStar/Window.h"

#include <memory>

struct GLFWwindow;

namespace RedStar
{
	class GLFWWindow : public Window
	{
	public:
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