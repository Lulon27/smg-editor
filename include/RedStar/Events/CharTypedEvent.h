#pragma once

#include "RedStar/Events/WindowEvent.h"
#include "RedStar/Input.h"
#include <sstream>
#include <bitset>
#include <iomanip>

namespace RedStar
{
	/**
	 * @brief Event that is fired if a character was typed.
	 */
	class CharTypedEvent : public WindowEvent
	{
		EVENT_CLASS(CharTypedEvent)
	public:
		CharTypedEvent(Window* window, uint32_t codepoint)
			: WindowEvent(window), m_codepoint(codepoint) {};

	public:
		/**
		 * @brief Returns the codepoint of the typed character.
		 * @return the codepoint
		 */
		uint32_t getCodepoint() const
		{
			return m_codepoint;
		}

		/**
		 * @brief Sets the codepoint that was typed.
		 * @param[in] codepoint the new codepoint
		 */
		void setCodepoint(uint32_t codepoint)
		{
			m_codepoint = codepoint;
		}

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << "[U+" << std::setfill('0') << std::setw(4) << std::hex << m_codepoint << "]";
			return ss.str();
		}

	private:
		uint32_t m_codepoint;
	};
}
