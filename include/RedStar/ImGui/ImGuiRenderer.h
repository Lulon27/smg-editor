#pragma once

#include "RedStar/Window.h"
#include "RedStar/GraphicsContext.h"

namespace RedStar
{
	struct ImGuiOpenGL3InitInfo
	{
		const char* glslVersion;
	};

	class ImGuiRenderer
	{
	public:
		static void initialize(Window* window, GraphicsContext::API graphicsApi, const void* apiInfo);
		static void deinitialize();
		static void newFrame();
		static void render();

	protected:
		virtual ~ImGuiRenderer() = default;

		virtual void initializeImpl(Window* window, const void* apiInfo) = 0;
		virtual void deinitializeImpl() = 0;
		virtual void newFrameImpl() = 0;
		virtual void renderImpl() = 0;
	};
}
