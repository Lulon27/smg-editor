#pragma once

#include "RedStar/Events/WindowEvent.h"
#include "RedStar/Input.h"
#include <sstream>

namespace RedStar
{
	/**
	 * @brief Event related to mouse buttons.
	 */
	class MouseButtonEvent : public WindowEvent
	{
	protected:
		MouseButtonEvent(Window* window, const MouseButtonData* button)
			: WindowEvent(window), m_button(button) {};

	public:

		/**
		 * @brief Returns the mouse button that this event handles.
		 * @return the event mouse button
		 */
		const MouseButtonData& getButton() const
		{
			return *m_button;
		}

		/**
		 * @brief Sets the mouse button that is handled by this event.
		 * @param[in] key the new event mouse button
		 */
		void setButton(const MouseButtonData* button)
		{
			m_button = button;
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

	/**
	 * @brief Event that is fired if a mouse button was pressed.
	 */
	class MouseButtonPressedEvent : public MouseButtonEvent
	{
		EVENT_CLASS(MouseButtonPressedEvent)
	public:
		MouseButtonPressedEvent(Window* window, const MouseButtonData* button, const Input::Mods::ModsField& mods)
			: MouseButtonEvent(window, button), m_mods(mods) {}

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << "[" << getButton().code << ", \"" << getButton().name << "\""
				<< ", mods=" << std::bitset<8>(m_mods.getMods()).to_string() << "]";
			return ss.str();
		}

		/**
		 * @brief Returns the modifiers that are active during this event.
		 * @return the event mouse button modifiers
		 */
		Input::Mods::ModsField& getMods()
		{
			return m_mods;
		}

	private:
		Input::Mods::ModsField m_mods;
	};

	/**
	 * @brief Event that is fired if a mouse button was released.
	 */
	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
		EVENT_CLASS(MouseButtonReleasedEvent)
	public:
		MouseButtonReleasedEvent(Window* window, const MouseButtonData* button, const Input::Mods::ModsField& mods)
			: MouseButtonEvent(window, button), m_mods(mods) {}

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << "[" << getButton().code << ", \"" << getButton().name << "\""
				<< ", mods=" << std::bitset<8>(m_mods.getMods()).to_string() << "]";
			return ss.str();
		}

		/**
		 * @brief Returns the modifiers that are active during this event.
		 * @return the event mouse button modifiers
		 */
		Input::Mods::ModsField& getMods()
		{
			return m_mods;
		}

	private:
		Input::Mods::ModsField m_mods;
	};

	/**
	 * @brief Event that is fired if the mouse wheel was scrolled.
	 */
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

		/**
		 * @brief Horizontal scroll amount from -1 to +1 where -1 is left.
		 */
		double xOffset;

		/**
		 * @brief Vertical scroll amount from -1 to +1 where -1 is down.
		 */
		double yOffset;
	};

	/**
	 * @brief Event that is fired if the mouse position changed.
	 */
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

		/**
		 * @brief New X-position in pixels where the origin is the top left corner of the window area.
		 */
		double xPos;

		/**
		 * @brief New Y-position in pixels where the origin is the top left corner of the window area.
		 */
		double yPos;
	};
}
