#pragma once

#include "RedStar/Window.h"
#include "RedStar/GraphicsContext.h"

namespace RedStar
{
	/**
	 * @brief Struct that contains information about ImGui initialization with OpenGL 3.
	 */
	struct ImGuiOpenGL3InitInfo
	{
		const char* glslVersion;
	};

	/**
	 * @brief Helper class to abstract away the Dear ImGui rendering backends.
	 * 
	 * This class contains abstractions of common ImGui rendering functions like
	 * ImGui::NewFrame(), ImGui::Render() and ImGui::CreateContext();
	 * These functions usually have to be called together with platform specific code
	 * and this class aims to abstract this away.
	 * 
	 * The static functions can be used to initialize and deinitialize ImGui.
	 * ImGuiRenderer::newFrame() and ImGuiRenderer::render() can be used as platform independent
	 * replacements of ImGui::NewFrame() and ImGui::Render(), respectively.
	 * 
	 * This currently only works using only one window because this
	 * application will probably never have more than one window.
	 */
	class ImGuiRenderer
	{
	public:

		/**
		 * @brief Initializes an ImGui context and backend (registers appropriate window callbacks, etc.).
		 * 
		 * This function automatically detects the right windowing API based on the
		 * window parameter.
		 * The apiInfo parameter expects the correct struct corresponding to the graphics API,
		 * e. g. ImGuiOpenGL3InitInfo for OpenGL 3.
		 * 
		 * @param[in] window		Window used for initialization
		 * @param[in] graphicsApi	Graphics API that ImGui should use
		 * @param[in] apiInfo		Initialization info for the graphics API
		 */
		static void initialize(Window* window, GraphicsContext::API graphicsApi, const void* apiInfo);

		/**
		 * @brief Frees resources associated with this renderer and destroys the ImGui context.
		 */
		static void deinitialize();

		/**
		 * @brief Usage the same as ImGui::NewFrame().
		 */
		static void newFrame();

		/**
		 * @brief Usage the same as ImGui::Render().
		 */
		static void render();

	protected:
		virtual ~ImGuiRenderer() = default;

		// Methods that should be overridden by renderer implementations

		virtual void initializeImpl(Window* window, const void* apiInfo) = 0;
		virtual void deinitializeImpl() = 0;
		virtual void newFrameImpl() = 0;
		virtual void renderImpl() = 0;
	};
}
