#pragma once

#include <vector>
#include <memory>

#include "RedStar/Layer.h"

namespace RedStar
{
	/**
	 * @brief A stack like structure that consists of Layers. Events can be passed to these Layers.
	 */
	class LayerStack
	{
	public:
		/**
		 * @brief Pushes a layer onto the layer stack.
		 * @param[in] layer the layer to push onto the stack
		 */
		void pushLayer(std::shared_ptr<Layer> layer);

		/**
		 * @brief Pops a layer from the layer stack.
		 * @param[in] layer the layer to pop from the stack
		 */
		void popLayer(std::shared_ptr<Layer> layer);

		/**
		 * @brief Clears the layer stack.
		 */
		void clear();

		/**
		 * @brief Passes an event to all layers on the stack.
		 * 
		 * Passes an event to all layers on the stack.
		 * The event is passed from top to bottom
		 * so the layer that was added last will receive the
		 * event first. If a layer handles the event,
		 * the event is not propagated further.
		 * 
		 * @param[in] event the event
		 */
		void onEvent(Event& event);

		/**
		 * @brief Updates all layers on the stack.
		 *
		 * Updates all layers on the stack.
		 * The layers are updated from bottom to top
		 * so the layer that was added first will be updated first.
		 * This is called every tick in the main loop
		 * after events have been polled by the window.
		 */
		void onUpdate();

	private:
		std::vector<std::shared_ptr<Layer>> m_layers;
	};
}
