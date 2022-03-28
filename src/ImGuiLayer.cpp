#include "RedStar/ImGuiLayer.h"
#include "RedStar/RedStarApp.h"

#include <imgui.h>
#include "RedStar/ImGui/ImGuiRenderer.h"

namespace RedStar
{
    ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {}

	void ImGuiLayer::onUpdate()
	{
        ImGuiIO& io = ImGui::GetIO();

        ImGuiRenderer::newFrame();

        ImGui::Begin("Hello, world!");

        ImGui::Text("Welcome new galaxy!");

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
        ImGui::End();

        ImGuiRenderer::render();
	}

    bool ImGuiLayer::onKeyPressed(KeyPressedEvent& event)
    {
        if (ImGui::GetIO().WantCaptureKeyboard) return true;
        return false;
    }

    bool ImGuiLayer::onKeyReleased(KeyReleasedEvent& event)
    {
        if (ImGui::GetIO().WantCaptureKeyboard) return true;
        return false;
    }

    bool ImGuiLayer::onKeyTyped(KeyTypedEvent& event)
    {
        if (ImGui::GetIO().WantCaptureKeyboard) return true;
        return false;
    }

    bool ImGuiLayer::onCharTyped(CharTypedEvent& event)
    {
        if (ImGui::GetIO().WantCaptureKeyboard) return true;
        return false;
    }

    bool ImGuiLayer::onMouseButtonPressed(MouseButtonPressedEvent& event)
    {
        if (ImGui::GetIO().WantCaptureMouse) return true;
        return false;
    }

    bool ImGuiLayer::onMouseButtonReleased(MouseButtonReleasedEvent& event)
    {
        if (ImGui::GetIO().WantCaptureMouse) return true;
        return false;
    }

    bool ImGuiLayer::onMouseScrolled(MouseScrolledEvent& event)
    {
        if (ImGui::GetIO().WantCaptureMouse) return true;
        return false;
    }
}
