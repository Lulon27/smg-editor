#pragma once

#include "RedStar/Logging.h"
#include "RedStar/Window.h"

namespace RedStar
{
	class RedStarApp
	{
	public:
		RedStarApp();
		~RedStarApp();

		void run();

		bool isRunning()
		{
			return m_running;
		}

		const Logger& getLogger()
		{
			return m_appLogger;
		}

		static RedStarApp* get()
		{
			return s_instance;
		}

	private:
		bool m_running = false;
		Logger m_appLogger;
		std::unique_ptr<Window> m_window;

		static RedStarApp* s_instance;
	};
}