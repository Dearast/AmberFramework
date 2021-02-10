#include "Logger.h"

namespace Amber
{
    std::shared_ptr<spdlog::logger> Logger::s_coreLogger;
    std::shared_ptr<spdlog::logger> Logger::s_clientLogger;
    std::string Logger::s_clientLoggerName = "[SOFTWARE ]";

    void Logger::Set_ClientLoggerName(const std::string &t_newName)
    {
        s_clientLoggerName = t_newName;
        s_clientLogger = spdlog::stdout_color_mt(Logger::s_clientLoggerName);
    }

    void Logger::Init()
    {
        spdlog::set_pattern("[%T:%f] %^%n%$: %v");

        s_coreLogger = spdlog::stdout_color_mt("[  AMBER  ]");
        s_coreLogger->set_level(spdlog::level::trace);

        s_clientLogger = spdlog::stdout_color_mt(Logger::s_clientLoggerName);
        s_clientLogger->set_level(spdlog::level::trace);

        AMBER_CORE_INFO("Logger initialized successful");
    }
}
