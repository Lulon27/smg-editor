#include "RedStar/Logging.h"
#include "RedStar/Assert.h"

namespace RedStar
{
	Logger Logger::s_assertLogger = Logger(RS_ASSERT_LOGGER_NAME);

#ifndef RS_DISABLE_LOGGING
	static spdlog::level::level_enum convertToSpdlogLevel(Logger::Level level)
	{
		switch (level)
		{
			case RedStar::Logger::Level::Trace:		return spdlog::level::trace;
			case RedStar::Logger::Level::Debug:		return spdlog::level::debug;
			case RedStar::Logger::Level::Info:		return spdlog::level::info;
			case RedStar::Logger::Level::Warn:		return spdlog::level::warn;
			case RedStar::Logger::Level::Error:		return spdlog::level::err;
			case RedStar::Logger::Level::Critical:	return spdlog::level::critical;
			case RedStar::Logger::Level::Off:		return spdlog::level::off;
		}
		RS_ASSERT(false, "Unknown log level");
		return spdlog::level::off;
	}
#endif

	//////////////////////////////////
	//           LOGGER             //
	//////////////////////////////////


#ifndef RS_DISABLE_LOGGING
	Logger::Logger() : m_logger(nullptr) {}
	Logger::Logger(const std::string& name) : m_logger(spdlog::stdout_color_mt(name)) {}
#else
	Logger::Logger() {}
	Logger::Logger(const std::string& name) {}
#endif

	void Logger::setLevel(Logger::Level level)
	{
#ifndef RS_DISABLE_LOGGING
		m_logger->set_level(convertToSpdlogLevel(level));
#endif
	}

	Logger Logger::create(const std::string& name, Logger::Level initLevel)
	{
		//I think it's okay to copy the logger as it's only a shared pointer
		Logger l(name);
		l.setLevel(initLevel);
		return l;
	}

	Logger Logger::get(const std::string& name)
	{
		Logger l;

#ifndef RS_DISABLE_LOGGING
		l.m_logger = spdlog::get(name);
#endif

		return l;
	}
}