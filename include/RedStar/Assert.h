#pragma once

#ifdef RS_DISABLE_ASSERT
	#define DEBUG_BREAK()
	#define RS_ASSERT(condition, ...)
#else
	#ifdef _MSC_VER
		#define DEBUG_BREAK() __debugbreak()
	#else
		#define DEBUG_BREAK() /* Not Visual Studio */
	#endif // _MSC_VER

	#include "RedStar/Logging.h"
	#define RS_ASSERT(condition, ...) if(!(condition)){ ::RedStar::Logger::getAssertLogger().critical(__VA_ARGS__); DEBUG_BREAK();}

#endif // NDEBUG

