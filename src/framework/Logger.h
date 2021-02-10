#pragma once

#include "Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <string>

namespace Amber
{
    class AMBER_API Logger
    {
    private:
    static std::shared_ptr<spdlog::logger> s_coreLogger;
    static std::shared_ptr<spdlog::logger> s_clientLogger;
    static std::string s_clientLoggerName;
    public:
    static void Init();
    static void Set_ClientLoggerName(const std::string& t_newName);
    inline static std::shared_ptr<spdlog::logger>& Get_CoreLogger() { return s_coreLogger; }
    inline static std::shared_ptr<spdlog::logger>& Get_ClientLogger() { return s_clientLogger; }
    };
}

#define AMBER_CORE_FATAL(...)  ::Amber::Logger::Get_CoreLogger()->critical(__VA_ARGS__)
#define AMBER_CORE_ERROR(...)  ::Amber::Logger::Get_CoreLogger()->error(__VA_ARGS__)
#define AMBER_CORE_WARN(...)   ::Amber::Logger::Get_CoreLogger()->warn(__VA_ARGS__)
#define AMBER_CORE_INFO(...)   ::Amber::Logger::Get_CoreLogger()->info(__VA_ARGS__)
#define AMBER_CORE_TRACE(...)  ::Amber::Logger::Get_CoreLogger()->trace(__VA_ARGS__)

#define AMBER_CLIENT_FATAL(...)::Amber::Logger::Get_ClientLogger()->critical(__VA_ARGS__)
#define AMBER_CLIENT_ERROR(...)::Amber::Logger::Get_ClientLogger()->error(__VA_ARGS__)
#define AMBER_CLIENT_WARN(...) ::Amber::Logger::Get_ClientLogger()->warn(__VA_ARGS__)
#define AMBER_CLIENT_INFO(...) ::Amber::Logger::Get_ClientLogger()->info(__VA_ARGS__)
#define AMBER_CLIENT_TRACE(...)::Amber::Logger::Get_ClientLogger()->trace(__VA_ARGS__)
