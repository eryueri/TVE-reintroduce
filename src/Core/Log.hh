#pragma once

#include "pch.hh"

namespace spdlog {
    class logger;
}

namespace TVE {
    class Log {
    public:
        static void init();

        static void trace(std::string msg);
        static void debug(std::string msg);
        static void info(std::string msg);
        static void warn(std::string msg);
        static void error(std::string msg);
        static void critical(std::string msg);
    private:
        static std::shared_ptr<spdlog::logger> _consoleLogger;
    };
    #define LOG_INIT() TVE::Log::init()
    #define LOG_TRACE(msg) TVE::Log::trace(msg)
    #define LOG_DEBUG(msg) TVE::Log::debug(msg)
    #define LOG_INFO(msg) TVE::Log::info(msg)
    #define LOG_WARN(msg) TVE::Log::warn(msg)
    #define LOG_ERROR(msg) TVE::Log::error(msg)
    #define LOG_CRITICAL(msg) TVE::Log::critical(msg)
}