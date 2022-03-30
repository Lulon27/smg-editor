#include "RedStar/ImGuiLayer.h"
#include "RedStar/RedStarApp.h"

#include <imgui.h>
#include "RedStar/ImGui/ImGuiRenderer.h"

namespace RedStar
{
    ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {}

    static void setStyle()
    {
        ImVec4* colors = ImGui::GetStyle().Colors;
        colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
        colors[ImGuiCol_TextDisabled]           = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
        colors[ImGuiCol_WindowBg]               = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
        colors[ImGuiCol_ChildBg]                = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
        colors[ImGuiCol_PopupBg]                = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
        colors[ImGuiCol_Border]                 = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
        colors[ImGuiCol_BorderShadow]           = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
        colors[ImGuiCol_FrameBg]                = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
        colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
        colors[ImGuiCol_FrameBgActive]          = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
        colors[ImGuiCol_TitleBg]                = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
        colors[ImGuiCol_TitleBgActive]          = ImVec4(0.20f, 0.04f, 0.06f, 1.00f);
        colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
        colors[ImGuiCol_MenuBarBg]              = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
        colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
        colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
        colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
        colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.45f, 0.45f, 0.45f, 1.00f);
        colors[ImGuiCol_CheckMark]              = ImVec4(0.85f, 0.25f, 0.35f, 1.00f);
        colors[ImGuiCol_SliderGrab]             = ImVec4(0.45f, 0.45f, 0.45f, 1.00f);
        colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
        colors[ImGuiCol_Button]                 = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
        colors[ImGuiCol_ButtonHovered]          = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
        colors[ImGuiCol_ButtonActive]           = ImVec4(0.27f, 0.16f, 0.18f, 1.00f);
        colors[ImGuiCol_Header]                 = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
        colors[ImGuiCol_HeaderHovered]          = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
        colors[ImGuiCol_HeaderActive]           = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
        colors[ImGuiCol_Separator]              = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
        colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
        colors[ImGuiCol_SeparatorActive]        = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);
        colors[ImGuiCol_ResizeGrip]             = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
        colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
        colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.45f, 0.45f, 0.45f, 1.00f);
        colors[ImGuiCol_Tab]                    = ImVec4(0.18f, 0.18f, 0.18f, 1.00f);
        colors[ImGuiCol_TabHovered]             = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
        colors[ImGuiCol_TabActive]              = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
        colors[ImGuiCol_TabUnfocused]           = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
        colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.18f, 0.18f, 0.18f, 1.00f);
        colors[ImGuiCol_DockingPreview]         = ImVec4(0.85f, 0.25f, 0.35f, 1.00f);
        colors[ImGuiCol_DockingEmptyBg]         = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
        colors[ImGuiCol_PlotLines]              = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
        colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.15f, 0.22f, 1.00f);
        colors[ImGuiCol_PlotHistogram]          = ImVec4(0.85f, 0.14f, 0.19f, 1.00f);
        colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(0.95f, 0.30f, 0.35f, 1.00f);
        colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
        colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.05f, 0.05f, 0.05f, 1.00f);
        colors[ImGuiCol_TableBorderLight]       = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
        colors[ImGuiCol_TableRowBg]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        colors[ImGuiCol_TableRowBgAlt]          = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
        colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.78f, 0.17f, 0.27f, 1.00f);
        colors[ImGuiCol_DragDropTarget]         = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
        colors[ImGuiCol_NavHighlight]           = ImVec4(0.85f, 0.25f, 0.35f, 1.00f);
        colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(0.85f, 0.25f, 0.35f, 1.00f);
        colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(1.00f, 1.00f, 1.00f, 0.25f);
        colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.00f, 0.00f, 0.00f, 0.50f);

        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowPadding = ImVec2(8.00f, 8.00f);
        style.FramePadding = ImVec2(8.00f, 6.00f);
        style.CellPadding = ImVec2(6.00f, 6.00f);
        style.ItemSpacing = ImVec2(8.00f, 8.00f);
        style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
        style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
        style.IndentSpacing = 24;
        style.ScrollbarSize = 16;
        style.GrabMinSize = 10;
        style.WindowBorderSize = 1;
        style.ChildBorderSize = 1;
        style.PopupBorderSize = 1;
        style.FrameBorderSize = 1;
        style.TabBorderSize = 1;
        style.WindowRounding = 8;
        style.ChildRounding = 4;
        style.FrameRounding = 6;
        style.PopupRounding = 4;
        style.ScrollbarRounding = 9;
        style.GrabRounding = 4;
        style.LogSliderDeadzone = 4;
        style.TabRounding = 4;
        style.WindowMenuButtonPosition = ImGuiDir_None;
    }

    static void dockSpace()
    {
        static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::Begin("DockSpace Host", NULL, window_flags);
        ImGui::PopStyleVar();

        ImGui::PopStyleVar(2);

        ImGuiID dockspace_id = ImGui::GetID("DockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None);

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                ImGui::MenuItem("Save");
                ImGui::MenuItem("Export...");
                ImGui::Separator();
                ImGui::MenuItem("Close");

                ImGui::EndMenu();
            }

            ImGui::EndMenuBar();
        }
        ImGui::End();
    }

    void ImGuiLayer::onAttach()
    {
        setStyle();
    }

	void ImGuiLayer::onUpdate()
	{
        ImGuiRenderer::newFrame();

        ImGuiIO& io = ImGui::GetIO();
        dockSpace();

        if(ImGui::Begin("Project explorer"))
        {
            if (ImGui::TreeNode("Galaxies"))
            {
                ImGui::BulletText("Galaxy 1");
                ImGui::BulletText("Galaxy 2");
                ImGui::BulletText("Galaxy 3");
                ImGui::TreePop();
                ImGui::Separator();
            }

            if (ImGui::TreeNode("Models"))
            {
                ImGui::BulletText("Model 1");
                ImGui::BulletText("Model 2");
                ImGui::TreePop();
                ImGui::Separator();
            }
        }
        ImGui::End();

        if(ImGui::Begin("Object outline"))
        {

            ImGui::BulletText("Object 1");
            ImGui::BulletText("Object 2");
            ImGui::BulletText("Object 3");
            ImGui::BulletText("Object 4");

        }
        ImGui::End();

        if(ImGui::Begin("Object settings"))
        {
            static float transform[9] {};
            ImGui::InputFloat3("Position", transform);
            ImGui::InputFloat3("Rotation", transform + 3);
            ImGui::InputFloat3("Scale", transform + 6);

        }
        ImGui::End();

        if (ImGui::Begin("Editor"))
        {
            ImGui::Text("Welcome new galaxy!");
            ImGui::NewLine();
            ImGui::Text("This program is very early in development.");
            ImGui::Text("This is only here to show that the program works.");
            ImGui::Text("There is nothing else to see here.");
            ImGui::NewLine();
            ImGui::Text("The editor layout and style will probably look similar to here, however I'm not sure.");
            ImGui::NewLine();
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
        }
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
