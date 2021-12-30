#include "RedStar/RedStarApp.h"

namespace RedStar
{
	RedStarApp* RedStarApp::s_instance = nullptr;

	RedStarApp::RedStarApp()
	{
		RS_ASSERT(!s_instance, "Application can only be instantiated once!");
		s_instance = this;
	}

	RedStarApp::~RedStarApp()
	{

	}

	void RedStarApp::run()
	{
		m_running = true;
		while (m_running)
		{

		}
	}
}