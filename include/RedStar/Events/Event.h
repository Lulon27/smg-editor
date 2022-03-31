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

	/**
	 * @brief Contains all event types that can be used to check
	 * if an event is of a specific type.
	 */
	enum class EventType
	{
		// If a new event is created it must be added to this enum!

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

		/**
		 * @brief Returns the event type which can be used to check if the event is of a specific type
		 * @return the event type
		 */
		virtual EventType getType() const = 0;

		/**
		 * @brief Returns name of the event.
		 * @return the event name
		 */
		virtual std::string getName() const = 0;

		/**
		 * @brief Converts the event to a readable user friendly string.
		 * @return user friendly string that represents the event
		 */
		virtual std::string toString() const
		{
			return getName();
		}
	};

	/**
	 * @brief A queue that contains events so they can be buffered and handled at a specific time
	 * 
	 * This is currently implemented using std::queue.
	 */
	class EventQueue
	{
		using OnEventFn = std::function<void(Event&)>;
	public:
		/**
		 * @brief Constructs an empty event queue.
		 */
		EventQueue() {}

		/**
		 * @brief Adds an event to the queue.
		 * 
		 * The event is not passed directly but constructed by this method.
		 * 
		 * @param[in] T		type of the event
		 * @param[in] args	constructor arguments of the event
		 */
		template<typename T, class... Args>
		void pushEvent(Args... args)
		{
			m_events.push(std::make_unique<T>(args...));
		}

		/**
		 * @brief Returns the amount of events in this queue.
		 * @return the amount of events in this queue
		 */
		size_t size() const
		{
			return m_events.size();
		}

		/**
		 * @brief Sets the function that gets called for every processed event.
		 * 
		 * The event parameter of the event callback is only
		 * guaranteed to be valid for the duration of the callback function
		 * so the event should not be referenced afterwards.
		 * 
		 * @param[in] callback event callback function
		 */
		void setOnEvent(OnEventFn callback)
		{
			m_callbackOnEvent = callback;
		}

		/**
		 * @brief Processes all events that are in the queue.
		 * 
		 * If the event callback function is not set this method does nothing.
		 * The callback function can be set using setOnEvent().
		 * The callback function is called for every event that is processed.
		 * After the callback function returns, the event will get destroyed
		 * so it should not be referenced afterwards.
		 */
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
