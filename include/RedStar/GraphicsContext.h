#pragma once

namespace RedStar
{
	class GraphicsContext
	{
	public:
		enum class API
		{
			None,
			OpenGL
		};

	public:
		virtual ~GraphicsContext() = default;

		virtual bool init() = 0;
		virtual void swapBuffers() = 0;
		virtual void setVSync(bool vsync) = 0;
	};
}