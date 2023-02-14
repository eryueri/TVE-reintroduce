#include "Core/Log.hh"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace TVE {
    std::shared_ptr<spdlog::logger> Log::_consoleLogger;
    
    void Log::init()
    {
        auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        _consoleLogger = std::make_shared<spdlog::logger>("TVE", sink);
        _consoleLogger->set_pattern("%^[%T] %n: %v%$");
        _consoleLogger->set_level(spdlog::level::trace);
        _consoleLogger->flush_on(spdlog::level::trace);
    }
    
    void Log::trace(std::string msg)
    {
       _consoleLogger->trace(msg); 
    }

    void Log::debug(std::string msg)
    {
       _consoleLogger->debug(msg); 
    }

    void Log::info(std::string msg)
    {
       _consoleLogger->info(msg); 
    }

    void Log::warn(std::string msg)
    {
       _consoleLogger->warn(msg); 
    }

    void Log::error(std::string msg)
    {
       _consoleLogger->error(msg); 
    }

    void Log::critical(std::string msg)
    {
       _consoleLogger->critical(msg); 
    }

}