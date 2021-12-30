#pragma once

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

		static RedStarApp* get()
		{
			return s_instance;
		}

	private:
		bool m_running = false;

		static RedStarApp* s_instance;
	};
}