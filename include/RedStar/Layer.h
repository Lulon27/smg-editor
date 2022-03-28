#pragma once

#include <string>

#include "RedStar/Events/KeyEvent.h"
#include "RedStar/Events/CharTypedEvent.h"
#include "RedStar/Events/MouseEvent.h"
#include "RedStar/Assert.h"

namespace RedStar
{
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
		virtual bool onWindowClose(WindowCloseEvent& ev) { return false; }
		virtual bool onWindowResize(WindowResizeEvent& ev) { return false; }

		virtual bool onKeyPressed(KeyPressedEvent& ev) { return false; }
		virtual bool onKeyReleased(KeyReleasedEvent& ev) { return false; }
		virtual bool onKeyTyped(KeyTypedEvent& ev) { return false; }
		virtual bool onCharTyped(CharTypedEvent& ev) { return false; }

		virtual bool onMouseButtonPressed(MouseButtonPressedEvent& ev) { return false; }
		virtual bool onMouseButtonReleased(MouseButtonReleasedEvent& ev) { return false; }
		virtual bool onMouseScrolled(MouseScrolledEvent& ev) { return false; }
		virtual bool onMouseMoved(MouseMovedEvent& ev) { return false; }

	protected:
		std::string m_dbgName;
	};
}
