#include "RedStar/RedStarApp.h"
#include "RedStar/Assert.h"
#include "RedStar/GLFWWindow.h"

namespace RedStar
{
	RedStarApp* RedStarApp::s_instance = nullptr;

	RedStarApp::RedStarApp()
	{
		RS_ASSERT(!s_instance, "Application can only be instantiated once!");
		s_instance = this;

		m_appLogger = Logger::create(RS_APP_LOGGER_NAME);
		m_appLogger.setLevel(Logger::Level::Trace);

		WindowProps props;
		props.width = 400;
		props.height = 400;
		props.title = "RedStar";
		props.maximized = false;
		props.visible = false;
		props.vsync = true;

		m_window = std::make_unique<GLFWWindow>(props);

		m_window->show();
	}

	RedStarApp::~RedStarApp()
	{

	}

	void RedStarApp::run()
	{
		m_running = true;
		while (m_running)
		{
			m_window->onUpdate();
			if (!m_window->isVisible())
			{
				m_running = false;
			}
		}
	}
}