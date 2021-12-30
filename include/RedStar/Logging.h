#pragma once

#include <spdlog/spdlog.h>

#define RS_TRACE(...)    spdlog::trace(__VA_ARGS__)
#define RS_INFO(...)     spdlog::info(__VA_ARGS__)
#define RS_WARN(...)     spdlog::warn(__VA_ARGS__)
#define RS_ERROR(...)    spdlog::error(__VA_ARGS__)
#define RS_CRITICAL(...) spdlog::critical(__VA_ARGS__)