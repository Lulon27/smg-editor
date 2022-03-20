#pragma once

#include <vector>
#include <memory>

#include "RedStar/Layer.h"

namespace RedStar
{
	class LayerStack
	{
	public:
		void pushLayer(std::shared_ptr<Layer> layer);
		void popLayer(std::shared_ptr<Layer> layer);

		void clear();

		void onEvent(Event& event);
		void onUpdate();

	private:
		std::vector<std::shared_ptr<Layer>> m_layers;
	};
}
