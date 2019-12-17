#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt//ostr.h"

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



//Core Log Macros
#define XJ_CORE_TRACE(...)	::Xj::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define XJ_CORE_INFO(...)	::Xj::Log::GetCoreLogger()->info(__VA_ARGS__)
#define XJ_CORE_WARN(...)	::Xj::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define XJ_CORE_ERROR(...)	::Xj::Log::GetCoreLogger()->error(__VA_ARGS__)
#define XJ_CORE_FATAL(...)	::Xj::Log::GetCoreLogger()->critical(__VA_ARGS__)


//Client Log Macros
#define XJ_TRACE(...)	::Xj::Log::GetClientLogger()->trace(__VA_ARGS__)
#define XJ_INFO(...)	::Xj::Log::GetClientLogger()->info(__VA_ARGS__)
#define XJ_WARN(...)	::Xj::Log::GetClientLogger()->warn(__VA_ARGS__)
#define XJ_ERROR(...)	::Xj::Log::GetClientLogger()->error(__VA_ARGS__)
#define XJ_FATAL(...)	::Xj::Log::GetClientLogger()->critical(__VA_ARGS__) 

