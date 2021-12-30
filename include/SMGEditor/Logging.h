#pragma once

#include <spdlog/spdlog.h>

#define SMG_TRACE(...)    spdlog::trace(__VA_ARGS__)
#define SMG_INFO(...)     spdlog::info(__VA_ARGS__)
#define SMG_WARN(...)     spdlog::warn(__VA_ARGS__)
#define SMG_ERROR(...)    spdlog::error(__VA_ARGS__)
#define SMG_CRITICAL(...) spdlog::critical(__VA_ARGS__)