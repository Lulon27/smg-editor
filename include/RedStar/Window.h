#pragma once

#include <stdint.h>

#include "RedStar/Events/Event.h"
#include "RedStar/GraphicsContext.h"

namespace RedStar
{
	struct WindowProps
	{
		uint16_t width = 400;
		uint16_t height = 400;
		const char* title = "";
		bool maximized = false;
		bool visible = true;
		bool vsync = true;
	};

	class Window
	{
	public:
		virtual ~Window() = default;

		virtual void onUpdate() = 0;

		virtual void* getNativeHandle() const = 0;

		virtual void show() = 0;
		virtual void hide() = 0;
		virtual bool isVisible() = 0;

		virtual void setVSync(bool vsync) = 0;
		virtual bool isVSyncEnabled() = 0;

		virtual GraphicsContext* getGraphicsContext() = 0;

		virtual bool getError() = 0;

		operator bool()
		{
			return !getError();
		}

		void setEventQueue(EventQueue* eventQueue)
		{
			m_eventCallbacks = eventQueue;
		}

		EventQueue* getEventQueue() const
		{
			return m_eventCallbacks;
		}

	protected:
		EventQueue* m_eventCallbacks = nullptr;
	};
}