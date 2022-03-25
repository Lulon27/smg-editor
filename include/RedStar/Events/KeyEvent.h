#pragma once

#include "RedStar/Events/WindowEvent.h"
#include "RedStar/Input.h"
#include <sstream>
#include <bitset>

namespace RedStar
{
	class KeyEvent : public WindowEvent
	{
	protected:
		KeyEvent(Window* window, const KeyData* key, const Input::Mods::ModsField& mods)
			: WindowEvent(window), m_mods(mods), m_key(key) {};

	public:
		const KeyData& getKey() const
		{
			return *m_key;
		}

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

		Input::Mods::ModsField& getMods()
		{
			return m_mods;
		}

	private:
		const KeyData* m_key;
		Input::Mods::ModsField m_mods;
	};

	class KeyPressedEvent : public KeyEvent
	{
		EVENT_CLASS(KeyPressedEvent)
	public:
		KeyPressedEvent(Window* window, const KeyData* key, const Input::Mods::ModsField& mods)
			: KeyEvent(window, key, mods) {}
	};

	class KeyReleasedEvent : public KeyEvent
	{
		EVENT_CLASS(KeyReleasedEvent)
	public:
		KeyReleasedEvent(Window* window, const KeyData* key, const Input::Mods::ModsField& mods)
			: KeyEvent(window, key, mods) {}
	};

	class KeyTypedEvent : public KeyEvent
	{
		EVENT_CLASS(KeyTypedEvent)
	public:
		KeyTypedEvent(Window* window, const KeyData* key, const Input::Mods::ModsField& mods)
			: KeyEvent(window, key, mods) {}
	};
}
