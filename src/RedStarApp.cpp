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
	}

	RedStarApp::~RedStarApp()
	{

	}

	void RedStarApp::onEvent(Event& event)
	{
		if (event.getType() == EventType::WindowCloseEvent)
		{
			m_running = false;

			//Don't continue processing remaining events
			//if the window was closed
			return;
		}
		m_layerStack.onEvent(event);
	}

	void RedStarApp::run()
	{
		RS_INFO("Starting the application...");

		m_eventQueue.setOnEvent(std::bind(&RedStarApp::onEvent, this, std::placeholders::_1));

		WindowProps props;
		props.width = 400;
		props.height = 400;
		props.title = "RedStar";
		props.maximized = false;
		props.visible = false;
		props.vsync = true;

		m_window = std::make_unique<GLFWWindow>(props, GraphicsContext::API::OpenGL);
		if (!*m_window)
		{
			return;
		}

		m_window->setEventQueue(&m_eventQueue);

		m_window->show();
		m_running = true;
		while (m_running)
		{
			m_window->onUpdate();
			m_layerStack.onUpdate();
			m_eventQueue.processEvents();
		}
		RS_INFO("Exiting the application...");
	}
}