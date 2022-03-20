#pragma once

#include "RedStar/Events/Event.h"
#include "RedStar/Window.h"
#include <sstream>

namespace RedStar
{
	class WindowEvent : public Event
	{
	protected:
		WindowEvent(Window* window) : m_window(window) {};

	public:
		Window* getWindow() const
		{
			return m_window;
		}

	private:
		Window* m_window;
	};

	class WindowCloseEvent : public WindowEvent
	{
		EVENT_CLASS(WindowCloseEvent)
	public:
		WindowCloseEvent(Window* window) : WindowEvent(window) {}
	};

	class WindowResizeEvent : public WindowEvent
	{
		EVENT_CLASS(WindowResizeEvent)
	public:
		WindowResizeEvent(Window* window, uint16_t width, uint16_t height) : WindowEvent(window), m_width(width), m_height(height) {}

		uint16_t getWidth() const
		{
			return m_width;
		}

		uint16_t getHeight() const
		{
			return m_height;
		}

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << "[" << m_width << ", " << m_height << "]";
			return ss.str();
		}

	private:
		uint16_t m_width;
		uint16_t m_height;
	};
}
