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
	#endif // _MSC_VER

#define RS_ASSERT(condition, ...) if(!(condition)){ RS_CRITICAL(__VA_ARGS__); DEBUG_BREAK();}
#endif // NDEBUG