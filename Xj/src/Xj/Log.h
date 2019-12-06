// Frank (6)

#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Xj {
	class XJ_API Log {
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

//Frank (6.5) 

//Core Log Macros
#define XJ_CORE_TRACE(...)	::Xj::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define XJ_CORE_INFO(...)	::Xj::Log::GetCoreLogger()->info(__VA_ARGS__)
#define XJ_CORE_WARN(...)	::Xj::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define XJ_CORE_ERROR(...)	::Xj::Log::GetCoreLogger()->error(__VA_ARGS__)
#define XJ_CORE_FATAL(...)	::Xj::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define XJ_CLIENT_TRACE(...)	::Xj::Log::GetClientLogger()->trace(__VA_ARGS__)
#define XJ_CLIENT_INFO(...)		::Xj::Log::GetClientLogger()->info(__VA_ARGS__)
#define XJ_CLIENT_WARN(...)		::Xj::Log::GetClientLogger()->warn(__VA_ARGS__)
#define XJ_CLIENT_ERROR(...)	::Xj::Log::GetClientLogger()->error(__VA_ARGS__)
#define XJ_CLIENT_FATAL(...)	::Xj::Log::GetClientLogger()->fatal(__VA_ARGS__)