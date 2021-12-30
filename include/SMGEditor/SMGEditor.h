#pragma once

#include "SMGEditor/Logging.h"

#ifdef NDEBUG
	#define DEBUG_BREAK()
	#define SMG_ASSERT(condition, ...)
#else
	#ifdef _MSC_VER
		#define DEBUG_BREAK() __debugbreak()
	#else
		#define DEBUG_BREAK() /* Not Visual Studio */
	#endif

	#define SMG_ASSERT(condition, ...) if(!(condition)){ SMG_CRITICAL(__VA_ARGS__); DEBUG_BREAK();}
#endif

namespace smg
{
	class Application
	{
	public:
		Application();
		~Application();

		void run();

		bool isRunning()
		{
			return m_running;
		}

		static Application* get()
		{
			return s_instance;
		}

	private:
		bool m_running = false;

		static Application* s_instance;
	};
}