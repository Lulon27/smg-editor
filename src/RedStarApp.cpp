#include "RedStar/RedStarApp.h"
#include "RedStar/Assert.h"
#include "RedStar/GLFWWindow.h"
#include "RedStar/ImGuiLayer.h"
#include "RedStar/ImGui/ImGuiRenderer.h"

#include <memory>
#include <glad/glad.h>

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
		props.width = 1200;
		props.height = 800;
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

		//Initialize Dear ImGui
		ImGuiOpenGL3InitInfo imGuiOpengl3Info;
		imGuiOpengl3Info.glslVersion = "#version 150 core";
		ImGuiRenderer::initialize(m_window.get(), GraphicsContext::API::OpenGL, &imGuiOpengl3Info);
		
		//Create layers
		m_layerStack.pushLayer(std::make_shared<ImGuiLayer>());

		m_window->show();
		m_running = true;
		while (m_running)
		{
			m_window->onUpdate();
			m_eventQueue.processEvents();

			//The following GL calls should be abstracted away in the future
			glClearColor(0.95f, 0.05f, 0.2f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			m_layerStack.onUpdate();

			if (m_window->isVisible())
			{
				m_window->getGraphicsContext()->swapBuffers();
			}
		}
		RS_INFO("Exiting the application...");

		ImGuiRenderer::deinitialize();
	}
}