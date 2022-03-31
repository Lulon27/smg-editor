#pragma once

#include <stdint.h>

#include "RedStar/Events/Event.h"
#include "RedStar/GraphicsContext.h"

namespace RedStar
{
	/**
	 * @brief A struct that contains information to contruct a window.
	 */
	struct WindowProps
	{
		uint16_t width = 400;
		uint16_t height = 400;
		const char* title = "";
		bool maximized = false;
		bool visible = true;
		bool vsync = true;
	};

	/**
	 * @brief Base class for all windows.
	 */
	class Window
	{
	public:
		virtual ~Window() = default;

		/**
		 * @brief This method is called every tick before everything else and mainly polls events.
		 * 
		 * A method that is called every tick before everything else in the main loop.
		 * This gives the window the opportunity to do important stuff like polling events.
		 * This method should not be used to swap buffers as this is done as a seperate step
		 * in the main loop.
		 */
		virtual void onUpdate() = 0;

		/**
		 * @brief Method that returns the underlying window handle of the windowing API.
		 *
		 * @return the underlying window handle of the windowing API
		 */
		virtual void* getNativeHandle() const = 0;

		/**
		 * @brief Makes the window visible.
		 */
		virtual void show() = 0;

		/**
		 * @brief Hides the window.
		 */
		virtual void hide() = 0;

		/**
		 * @brief Returns whether the window is visible.
		 * @return whether the window is visible
		 */
		virtual bool isVisible() = 0;

		/**
		 * @brief Turns V-Sync on or off.
		 * 
		 * @param[in] vsync whether V-Sync should be on or off
		 */
		virtual void setVSync(bool vsync) = 0;

		/**
		 * @brief Returns whether V-Sync is enabled.
		 * @return whether V-Sync is enabled
		 */
		virtual bool isVSyncEnabled() = 0;

		/**
		 * @brief Returns the graphics context that is used to render on the window.
		 * 
		 * @return the graphics context that is used to render on the window
		 */
		virtual GraphicsContext* getGraphicsContext() = 0;

		/**
		 * @brief Returns the current error state of this window.
		 * 
		 * The error state can be changed by this class at any time
		 * if an error occurs. This is only temporary because
		 * it is planned to replace this with exceptions.
		 * 
		 * @return the current error state of this window
		 */
		virtual bool getError() = 0;

		/**
		 * @brief Returns the current error state of this window.
		 *
		 * @return the current error state of this window
		 */
		operator bool()
		{
			return !getError();
		}

		/**
		 * @brief Sets the event queue that this window will redirect events to.
		 * 
		 * The window does not take ownership of the event queue thus the event
		 * queue's lifetime must be longer than the window's lifetime.
		 * 
		 * Once the event queue is set the window will enqueue all events that it receives.
		 *
		 * @param[in] the event queue that this window will redirect events to
		 */
		void setEventQueue(EventQueue* eventQueue)
		{
			m_eventCallbacks = eventQueue;
		}

		/**
		 * @brief Returns a pointer to the previously set event queue or nullptr if none was set.
		 * 
		 * @return a pointer to the previously set event queue or nullptr if none was set.
		 */
		EventQueue* getEventQueue() const
		{
			return m_eventCallbacks;
		}

	protected:
		EventQueue* m_eventCallbacks = nullptr;
	};
}