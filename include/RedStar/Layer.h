#pragma once

#include "RedStar/Events/KeyEvent.h"
#include "RedStar/Events/CharTypedEvent.h"
#include "RedStar/Events/MouseEvent.h"
#include "RedStar/Assert.h"

namespace RedStar
{
#define LAYER_EVENT_MAP_FN(eventType, fnName) case EventTypes::eventType: return fnName(*(eventType*)&ev);

	/**
	 * @brief A layer that can be pushed onto a layer stack.
	 */
	class Layer
	{
	public:
		virtual ~Layer() = default;

		/**
		 * @brief This is called once when the layer is pushed onto a layer stack.
		 */
		virtual void onAttach() {}

		/**
		 * @brief This is called once when the layer is popped from a layer stack.
		 */
		virtual void onDetach() {}

		/**
		 * @brief This is called when the layer is on a layer stack and the layer stack is updated.
		 * 
		 * Layers are updated from bottom to top, so the layer that was pushed onto the layer stack first
		 * is updated first.
		 */
		virtual void onUpdate() {}

		/**
		 * @brief This is called when the layer is on a layer stack and an event is passed to the layer stack.
		 *
		 * Layers receive events from top to bottom, so the layer that was pushed onto the layer stack first
		 * will receive the event last.
		 * The return value determines whether the event has been handled by the layer.
		 * If a layer handles an event, the layers that are below this layer on the stack (added before)
		 * will not receive the handled event.
		 * Some events can also be modified so the next layers that will receive the event
		 * will receive the modified version. This can for example be used to alter the mouse position
		 * that would get processed on the next layer.
		 * 
		 * Even tough this method is virtual, prefer to override the other more specific event methods,
		 * e. g. onWindowClose().
		 * 
		 * @param[in] event the event
		 * 
		 * @return true if the event has been handled by the layer
		 */
		virtual bool onEvent(Event& ev)
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

		/**
		 * @brief Returns the debug name that can be useful for logging.
		 * @return the debug name of the layer
		 */
		virtual const char* getDebugName() const
		{
			return "Layer";
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
	};
}
