#include "RedStar/ImGui/ImGuiRenderer_GLFW_OpenGL3.h"

#include "RedStar/GLFWWindow.h"

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <imgui.h>

namespace RedStar
{
	void ImGuiRenderer_GLFW_OpenGL3::initializeImpl(Window* window, const void* apiInfo)
	{
		m_window = reinterpret_cast<GLFWwindow*>(window->getNativeHandle());

		const ImGuiOpenGL3InitInfo* openGl3Info = reinterpret_cast<const ImGuiOpenGL3InitInfo*>(apiInfo);

		ImGui_ImplGlfw_InitForOpenGL(m_window, true);
		ImGui_ImplOpenGL3_Init(openGl3Info->glslVersion);
	}

	void ImGuiRenderer_GLFW_OpenGL3::deinitializeImpl()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
	}

	void ImGuiRenderer_GLFW_OpenGL3::newFrameImpl()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
	}

	void ImGuiRenderer_GLFW_OpenGL3::renderImpl()
	{
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}
}