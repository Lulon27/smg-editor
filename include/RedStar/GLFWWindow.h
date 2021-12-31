#pragma once

#include "Window.h"

namespace RedStar
{
	class GLFWWindow : public Window
	{
	public:
		GLFWWindow(const WindowProps& props);
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

	private:
		void* m_windowHandle = nullptr;
		bool m_vsyncEnabled = false;
	};
}