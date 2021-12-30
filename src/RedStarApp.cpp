#include "RedStar/RedStarApp.h"
#include "RedStar/Assert.h"

namespace RedStar
{
	RedStarApp* RedStarApp::s_instance = nullptr;

	RedStarApp::RedStarApp()
	{
		RS_ASSERT(!s_instance, "Application can only be instantiated once!");
		s_instance = this;

		m_appLogger = Logger::create(RS_APP_LOGGER_NAME);
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