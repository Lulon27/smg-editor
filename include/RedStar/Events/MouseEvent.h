#pragma once

#include "RedStar/Events/WindowEvent.h"
#include "RedStar/Input.h"
#include <sstream>

namespace RedStar
{
	class MouseButtonEvent : public WindowEvent
	{
	protected:
		MouseButtonEvent(Window* window, const MouseButtonData* button)
			: WindowEvent(window), m_button(button) {};

	public:
		const MouseButtonData& getButton() const
		{
			return *m_button;
		}

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << "[" << m_button->code << ", \"" << m_button->name << "\"]";
			return ss.str();
		}

	private:
		const MouseButtonData* m_button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
		EVENT_CLASS(MouseButtonPressedEvent)
	public:
		MouseButtonPressedEvent(Window* window, const MouseButtonData* button)
			: MouseButtonEvent(window, button) {}
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
		EVENT_CLASS(MouseButtonReleasedEvent)
	public:
		MouseButtonReleasedEvent(Window* window, const MouseButtonData* button)
			: MouseButtonEvent(window, button) {}
	};

	class MouseScrolledEvent : public WindowEvent
	{
		EVENT_CLASS(MouseScrolledEvent)
	public:
		MouseScrolledEvent(Window* window, double xOffset, double yOffset)
			: WindowEvent(window), xOffset(xOffset), yOffset(yOffset) {}

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << "[" << xOffset << ", " << yOffset << "]";
			return ss.str();
		}

	public:
		double xOffset;
		double yOffset;
	};

	class MouseMovedEvent : public WindowEvent
	{
		EVENT_CLASS(MouseMovedEvent)
	public:
		MouseMovedEvent(Window* window, double xPos, double yPos)
			: WindowEvent(window), xPos(xPos), yPos(yPos) {}

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << "[" << xPos << ", " << yPos << "]";
			return ss.str();
		}

	public:
		double xPos;
		double yPos;
	};
}
