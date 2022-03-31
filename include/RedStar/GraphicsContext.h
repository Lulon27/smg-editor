#pragma once

namespace RedStar
{
	/**
	 * @brief Graphics context that is used as an interface between a window and a graphics API.
	 *
	 * The GraphicsContext class is meant to provide a layer of abstraction between
	 * the windowing API and the graphics API, for example GLFW and OpenGL,
	 * in order to make it easier to introduce a new graphics API and make switching easier.
	 * It is unclear whether the graphics context class will stay the way it is
	 * in case a new graphics API will ever get added to this program which is kind of unlikely.
	 */
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

		/**
		 * @brief Initializes the graphics context.
		 */
		virtual bool init() = 0;

		/**
		 * @brief Swaps buffers.
		 */
		virtual void swapBuffers() = 0;

		/**
		 * @brief Turns V-Sync on or off.
		 *
		 * @param[in] vsync whether V-Sync should be on or off
		 */
		virtual void setVSync(bool vsync) = 0;
	};
}