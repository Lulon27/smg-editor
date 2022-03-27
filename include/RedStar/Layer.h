#pragma once

#include <string>

#include "RedStar/Events/KeyEvent.h"
#include "RedStar/Events/CharTypedEvent.h"
#include "RedStar/Events/MouseEvent.h"
#include "RedStar/Assert.h"

namespace RedStar
{
#define LAYER_EVENT_FN(eventType, fnName) virtual bool fnName(eventType& ev) { return false; }
#define LAYER_EVENT_MAP_FN(eventType, fnName) case EventType::eventType: return fnName(*(eventType*)&ev);

	class Layer
	{
	public:

		Layer(const std::string& dbgName = "Layer") : m_dbgName(dbgName) {}
		virtual ~Layer() = default;

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}

		bool onEvent(Event& ev)
		{
			switch (ev.getType())
			{
				LAYER_EVENT_MAP_FN(WindowCloseEvent,	onWindowClose)
				LAYER_EVENT_MAP_FN(WindowResizeEvent,	onWindowResize)

				LAYER_EVENT_MAP_FN(KeyPressedEvent,		onKeyPressed)
				LAYER_EVENT_MAP_FN(KeyReleasedEvent,	onKeyReleased)
				LAYER_EVENT_MAP_FN(KeyTypedEvent,		onKeyTyped)
				LAYER_EVENT_MAP_FN(CharTypedEvent,		onCharTyped)

				LAYER_EVENT_MAP_FN(MouseButtonPressedEvent,		onMouseButtonPressed)
				LAYER_EVENT_MAP_FN(MouseButtonReleasedEvent,	onMouseButtonReleased)
				LAYER_EVENT_MAP_FN(MouseScrolledEvent,			onMouseScrolled)
				LAYER_EVENT_MAP_FN(MouseMovedEvent,				onMouseMoved)
			}
			RS_ASSERT(false, "No mapping for event {}", ev.toString());
			return false;
		}

		const std::string& getDebugName() const
		{
			return m_dbgName;
		}

	protected:
		LAYER_EVENT_FN(WindowCloseEvent,		onWindowClose)
		LAYER_EVENT_FN(WindowResizeEvent,		onWindowResize)

		LAYER_EVENT_FN(KeyPressedEvent,			onKeyPressed)
		LAYER_EVENT_FN(KeyReleasedEvent,		onKeyReleased)
		LAYER_EVENT_FN(KeyTypedEvent,			onKeyTyped)
		LAYER_EVENT_FN(CharTypedEvent,			onCharTyped)

		LAYER_EVENT_FN(MouseButtonPressedEvent,		onMouseButtonPressed)
		LAYER_EVENT_FN(MouseButtonReleasedEvent,	onMouseButtonReleased)
		LAYER_EVENT_FN(MouseScrolledEvent,			onMouseScrolled)
		LAYER_EVENT_FN(MouseMovedEvent,				onMouseMoved)

	protected:
		std::string m_dbgName;
	};
}
