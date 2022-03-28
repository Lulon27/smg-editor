#include "RedStar/ImGui/ImGuiRenderer.h"

#include "RedStar/GLFWWindow.h"
#include "RedStar/Logging.h"
#include "RedStar/Assert.h"

#include "RedStar/ImGui/ImGuiRenderer_GLFW_OpenGL3.h"

#include <imgui.h>

namespace RedStar
{
	static enum class ImGuiBackend
	{
		None = -1,
		GLFW_OpenGL3
	};

	static const char* backendDebugName(ImGuiBackend backend)
	{
		switch (backend)
		{
			case ImGuiBackend::GLFW_OpenGL3: return "GLFW OpenGL 3";
			default: return "null";
		}
	}

	static Logger imguiLogger = Logger::create("ImGui Renderer", Logger::Level::Trace);
	static bool initialized = false;
	static ImGuiBackend backend = ImGuiBackend::None;
	static ImGuiRenderer* renderer = nullptr;

	static ImGuiRenderer* createRenderer(ImGuiBackend backend)
	{
		switch (backend)
		{
			case ImGuiBackend::GLFW_OpenGL3: return new ImGuiRenderer_GLFW_OpenGL3;
		}

		RS_ASSERT(false, "No ImGui Renderer found for backend {}", backend);
		return nullptr;
	}

	static ImGuiBackend determineImGuiBackend(Window* window, GraphicsContext::API graphicsApi)
	{
		Window* checkType = nullptr;
		if (checkType = dynamic_cast<GLFWWindow*>(window))
		{
			if (graphicsApi == GraphicsContext::API::OpenGL)
			{
				return ImGuiBackend::GLFW_OpenGL3;
			}
			else
			{
				RS_ASSERT(false, "No ImGui implementation for GLFW and graphics API {}", graphicsApi);
				return ImGuiBackend::None;
			}
		}
		
		RS_ASSERT(false, "No ImGui implementation for this kind of window!");
		return ImGuiBackend::None;
	}

	void ImGuiRenderer::initialize(Window* window, GraphicsContext::API graphicsApi, const void* apiInfo)
	{
		RS_ASSERT(window, "window cannot be null");
		RS_ASSERT(apiInfo, "apiInfo cannot be null");
		if (initialized)
		{
			RS_ASSERT(false, "Do not call ImGuiRenderer::initialize after it has already been initialized");
			return;
		}

		imguiLogger.debug("Initializing...");

		backend = determineImGuiBackend(window, graphicsApi);
		renderer = createRenderer(backend);

		if (renderer == nullptr)
		{
			return;
		}

		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

		//This application does not use viewports
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

		ImGui::StyleColorsDark();

		imguiLogger.debug("Initializing backend: {}", backendDebugName(backend));
		renderer->initializeImpl(window, apiInfo);

		initialized = true;
	}

	void ImGuiRenderer::deinitialize()
	{
		if (!initialized)
		{
			return;
		}

		imguiLogger.debug("Deinitializing...");

		renderer->deinitializeImpl();
		ImGui::DestroyContext();

		delete renderer;

		initialized = false;
	}

	void ImGuiRenderer::newFrame()
	{
		RS_ASSERT(initialized, "ImGui Renderer was not initialized before calling ImGuiRenderer::newFrame");

		renderer->newFrameImpl();
		ImGui::NewFrame();
	}

	void ImGuiRenderer::render()
	{
		RS_ASSERT(initialized, "ImGui Renderer was not initialized before calling ImGuiRenderer::render");

		ImGui::Render();
		renderer->renderImpl();
	}
}