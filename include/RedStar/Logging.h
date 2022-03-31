#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#define RS_LOG_FN_WRAPPER(fn_name)\
	template<typename... Args>\
	void fn_name(const char* text, Args &&... args) const {m_logger->fn_name(text, std::forward<Args>(args)...);}

#define RS_APP_LOGGER_NAME "RedStar"
#define RS_ASSERT_LOGGER_NAME "Assert"

#define RS_TRACE(...)		Logger::get(RS_APP_LOGGER_NAME).trace(__VA_ARGS__)
#define RS_DEBUG(...)		Logger::get(RS_APP_LOGGER_NAME).debug(__VA_ARGS__)
#define RS_INFO(...)		Logger::get(RS_APP_LOGGER_NAME).info(__VA_ARGS__)
#define RS_WARN(...)		Logger::get(RS_APP_LOGGER_NAME).warn(__VA_ARGS__)
#define RS_ERROR(...)		Logger::get(RS_APP_LOGGER_NAME).error(__VA_ARGS__)
#define RS_CRITICAL(...)	Logger::get(RS_APP_LOGGER_NAME).critical(__VA_ARGS__)

namespace RedStar
{
	class Logger
	{
		using LoggerType = std::shared_ptr<spdlog::logger>;

	public:
		enum class Level
		{
			Trace,
			Debug,
			Info,
			Warn,
			Error,
			Critical,
			Off
		};

	public:
		/**
		 * @brief Creates an empty logger that should not be used.
		 *
		 * Creates an empty logger. This will cause
		 * undefined behaviour if used.
		 */
		Logger() : m_logger() {}

		RS_LOG_FN_WRAPPER(trace);
		RS_LOG_FN_WRAPPER(debug);
		RS_LOG_FN_WRAPPER(info);
		RS_LOG_FN_WRAPPER(warn);
		RS_LOG_FN_WRAPPER(error);
		RS_LOG_FN_WRAPPER(critical);

		/**
		 * @brief Creates a logger with the specified name.
		 *
		 * Gets a logger by name. If the logger does not exist
		 * this will return an invalid logger that will cause
		 * undefined behaviour if used
		 * (should be changed in the future).
		 * 
		 * @param name[in]		the name the logger will have
		 * @param initLevel[in]	the initial logging level
		 *
		 * @return the created logger
		 */
		static Logger create(const std::string& name, Logger::Level initLevel = Logger::Level::Info)
		{
			Logger l(name);
			l.setLevel(initLevel);
			return l;
		}

		/**
		 * @brief Gets a logger by name.
		 * 
		 * Gets a logger by name. If the logger does not exist
		 * this will return an invalid logger that will cause
		 * undefined behaviour if used.
		 * 
		 * @param[in] name of the logger to get
		 * 
		 * @return the logger with the given name
		 */
		static Logger get(const std::string& name)
		{
			//I think it's okay to copy the logger as it's only a shared pointer
			return Logger(spdlog::get(name));
		}

		/**
		 * @brief Gets the logger used for assert messages.
		 *
		 * Gets a logger by name. If the logger does not exist
		 * this will return an invalid logger that will cause
		 * undefined behaviour if used.
		 *
		 * @return the assert logger
		 */
		static Logger getAssertLogger()
		{
			return s_assertLogger;
		}

		void setLevel(Logger::Level level);

	private:
		Logger(const std::string& name) : m_logger(spdlog::stdout_color_mt(name)) {}
		Logger(const LoggerType& logger) : m_logger(logger) {}

	private:
		LoggerType m_logger;

		static Logger s_assertLogger;
	};
}