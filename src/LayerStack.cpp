#include "RedStar/LayerStack.h"
#include "RedStar/Logging.h"

namespace RedStar
{
	void LayerStack::pushLayer(std::shared_ptr<Layer> layer)
	{
		m_layers.push_back(layer);
		layer->onAttach();
		RS_DEBUG("Pushed layer {}", layer->getDebugName());
	}

	void LayerStack::popLayer(std::shared_ptr<Layer> layer)
	{
		auto l = std::find(m_layers.begin(), m_layers.end(), layer);
		if (l != m_layers.end())
		{
			m_layers.erase(l);
			layer->onDetach();
			RS_DEBUG("Popped layer {}", layer->getDebugName());
		}
	}

	void LayerStack::clear()
	{
		m_layers.clear();
	}

	void LayerStack::onEvent(Event& ev)
	{
		for (auto it = m_layers.end(); it != m_layers.begin();)
		{
			//If onEvent returns true the event has been handled
			if ((*--it)->onEvent(ev))
			{
				break;
			}
		}
	}

	void LayerStack::onUpdate()
	{
		for (std::shared_ptr<Layer> l : m_layers)
		{
			l->onUpdate();
		}
	}
}
