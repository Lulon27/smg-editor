#pragma once

#include "RedStar/Events/WindowEvent.h"
#include "RedStar/Input.h"
#include <sstream>

namespace RedStar
{
	class KeyEvent : public WindowEvent
	{
	protected:
		KeyEvent(Window* window, const KeyData* key)
			: WindowEvent(window), m_key(key) {};

	public:
		const KeyData& getKey() const
		{
			return *m_key;
		}

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << getName() << "[" << m_key->code << ", \"" << m_key->name << "\"]";
			return ss.str();
		}

	private:
		const KeyData* m_key;
	};

	class KeyPressedEvent : public KeyEvent
	{
		EVENT_CLASS(KeyPressedEvent)
	public:
		KeyPressedEvent(Window* window, const KeyData* key)
			: KeyEvent(window, key) {}
	};

	class KeyReleasedEvent : public KeyEvent
	{
		EVENT_CLASS(KeyReleasedEvent)
	public:
		KeyReleasedEvent(Window* window, const KeyData* key)
			: KeyEvent(window, key) {}
	};

	class KeyTypedEvent : public KeyEvent
	{
		EVENT_CLASS(KeyTypedEvent)
	public:
		KeyTypedEvent(Window* window, const KeyData* key)
			: KeyEvent(window, key) {}
	};
}
