#include "RedStar/SMGEditor.h"

namespace RedStar
{
	Application* Application::s_instance = nullptr;

	Application::Application()
	{
		RS_ASSERT(!s_instance, "Application can only be instantiated once!");
		s_instance = this;
	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		m_running = true;
		while (m_running)
		{

		}
	}
}