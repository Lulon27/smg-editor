#pragma once

#include "RedStar/Assert.h"

#include <queue>
#include <memory>
#include <string>
#include <functional>

namespace RedStar
{
#define EVENT_CLASS(name) \
	public: \
	virtual EventType getType() const override { return EventType::name; }; \
	virtual std::string getName() const override { return #name; };

	enum class EventType
	{
		WindowCloseEvent = 1,
		WindowResizeEvent,

		KeyPressedEvent,
		KeyReleasedEvent,
		KeyTypedEvent,
		CharTypedEvent,

		MouseButtonPressedEvent,
		MouseButtonReleasedEvent,
		MouseScrolledEvent,
		MouseMovedEvent
	};

	class Event
	{
	public:
		virtual ~Event() = default;

		virtual EventType getType() const = 0;
		virtual std::string getName() const = 0;

		virtual std::string toString() const
		{
			return getName();
		}
	};

	class EventQueue
	{
		using OnEventFn = std::function<void(Event&)>;
	public:
		EventQueue() {}

		template<typename T, class... Args>
		void pushEvent(Args... args)
		{
			m_events.push(std::make_unique<T>(args...));
		}

		size_t size() const
		{
			return m_events.size();
		}

		void setOnEvent(OnEventFn callback)
		{
			m_callbackOnEvent = callback;
		}

		void processEvents()
		{
			if (!m_callbackOnEvent)
			{
				RS_ASSERT(false, "onEvent callback is not set!");
				return;
			}

			while (!m_events.empty())
			{
				auto& e = m_events.front();
				m_callbackOnEvent(*e);
				m_events.pop();
			}
		}

	private:
		EventQueue(const EventQueue&) = delete;
		EventQueue(EventQueue&&) = delete;
		EventQueue& operator=(const EventQueue&) = delete;
		EventQueue& operator=(EventQueue&&) = delete;

	private:
		std::queue<std::unique_ptr<Event>> m_events;
		OnEventFn m_callbackOnEvent = nullptr;
	};
}
