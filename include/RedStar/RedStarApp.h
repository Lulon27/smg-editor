#pragma once

#include "RedStar/Logging.h"

#ifdef NDEBUG
	#define DEBUG_BREAK()
	#define RS_ASSERT(condition, ...)
#else
	#ifdef _MSC_VER
		#define DEBUG_BREAK() __debugbreak()
	#else
		#define DEBUG_BREAK() /* Not Visual Studio */
	#endif

	#define RS_ASSERT(condition, ...) if(!(condition)){ RS_CRITICAL(__VA_ARGS__); DEBUG_BREAK();}
#endif

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