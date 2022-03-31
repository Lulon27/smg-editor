#pragma once

#include "RedStar/ImGui/ImGuiRenderer.h"

#include <GLFW/glfw3.h>

namespace RedStar
{
	/**
	 * @brief ImGui Renderer implementation for GLFW with OpenGL 3.
	 */
	class ImGuiRenderer_GLFW_OpenGL3 : public ImGuiRenderer
	{
	protected:
		virtual void initializeImpl(Window* window, const void* apiInfo) override;
		virtual void deinitializeImpl() override;
		virtual void newFrameImpl() override;
		virtual void renderImpl() override;

	private:
		GLFWwindow* m_window = nullptr;
	};
}