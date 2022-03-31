#pragma once

#include "RedStar/Events/WindowEvent.h"
#include "RedStar/Input.h"
#include <sstream>
#include <bitset>

namespace RedStar
{
	/**
	 * @brief Event related to keyboard keys.
	 */
	class KeyEvent : public WindowEvent
	{
	protected:
		KeyEvent(Window* window, const KeyData* key, const Input::Mods::ModsField& mods)
			: WindowEvent(window), m_mods(mods), m_key(key) {};

	public:
		/**
		 * @brief Returns the key that this event handles.
		 * @return the event key
		 */
		const KeyData& getKey() const
		{
			return *m_key;
		}

		/**
		 * @brief Sets the key that is handled by this event.
		 * @param[in] key the new event key
		 */
		void setKey(const KeyData* key)
		{
			m_key = key;
		}

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << "[" << m_key->code << ", \"" << m_key->name << "\""
				<< ", mods=" << std::bitset<8>(m_mods.getMods()).to_string() << "]";
			return ss.str();
		}

		/**
		 * @brief Returns the modifiers that are active during this event.
		 * @return the event key modifiers
		 */
		Input::Mods::ModsField& getMods()
		{
			return m_mods;
		}

	private:
		const KeyData* m_key;
		Input::Mods::ModsField m_mods;
	};

	/**
	 * @brief Event that is fired if a key was pressed.
	 */
	class KeyPressedEvent : public KeyEvent
	{
		EVENT_CLASS(KeyPressedEvent)
	public:
		KeyPressedEvent(Window* window, const KeyData* key, const Input::Mods::ModsField& mods)
			: KeyEvent(window, key, mods) {}
	};

	/**
	 * @brief Event that is fired if a key was released.
	 */
	class KeyReleasedEvent : public KeyEvent
	{
		EVENT_CLASS(KeyReleasedEvent)
	public:
		KeyReleasedEvent(Window* window, const KeyData* key, const Input::Mods::ModsField& mods)
			: KeyEvent(window, key, mods) {}
	};

	/**
	 * @brief Event that is fired if a key was typed (pressed and held down).
	 */
	class KeyTypedEvent : public KeyEvent
	{
		EVENT_CLASS(KeyTypedEvent)
	public:
		KeyTypedEvent(Window* window, const KeyData* key, const Input::Mods::ModsField& mods)
			: KeyEvent(window, key, mods) {}
	};
}
