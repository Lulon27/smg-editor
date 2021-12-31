#include "RedStar/Logging.h"
#include "RedStar/Assert.h"

namespace RedStar
{
	Logger Logger::s_assertLogger = Logger(RS_ASSERT_LOGGER_NAME);

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

	void Logger::setLevel(Logger::Level level)
	{
		m_logger->set_level(convertToSpdlogLevel(level));
	}
}