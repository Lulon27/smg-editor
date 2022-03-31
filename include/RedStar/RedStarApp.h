/*
 * \file RedStarApp.h
 */

#pragma once

#include "RedStar/Logging.h"
#include "RedStar/Window.h"
#include "RedStar/LayerStack.h"

namespace RedStar
{
	/**
	 * @brief This singleton class encapsulates the whole application.
	 */
	class RedStarApp
	{
	public:

		/**
		 * @brief Constructs an application object.
		 *
		 * Does some minimal initialization but the main work of the
		 * application should be done in the run() method.
		 */
		RedStarApp();
		~RedStarApp();

		/**
		 * @brief Starts the application.
		 * 
		 * This method starts the application and should only be called once.
		 * The application's lifecycle starts with the call of run() and
		 * ends when run() returns.
		 */
		void run();

		/**
		 * @brief Is called if the application recieves an event, for example from a window.
		 * 
		 * @param[in] event the event that was recieved
		 */
		void onEvent(Event& event);

		/**
		 * @brief Returns whether the application is currently running.
		 *
		 * @return whether the application is currently running
		 */
		bool isRunning()
		{
			return m_running;
		}

		/**
		 * @brief Returns the application's logger.
		 * 
		 * Returns the application's logger. The logger will have the tag "[<AppName>]",
		 * most likely "[RedStar]". This logger is meant to log application wide messages.
		 * 
		 * @return the application's logger used to log application wide messages
		 */
		const Logger& getLogger()
		{
			return m_appLogger;
		}

		/**
		 * @brief A means to get the application's singleton instance.
		 * 
		 * @return the application's singleton instance
		 */
		static RedStarApp* get()
		{
			return s_instance;
		}

	private:
		bool m_running = false;
		Logger m_appLogger;
		std::unique_ptr<Window> m_window;
		EventQueue m_eventQueue;
		LayerStack m_layerStack;

		static RedStarApp* s_instance;
	};
}