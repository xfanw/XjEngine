// Frank (6)

#include "Log.h"
#include "spdlog//sinks//stdout_color_sinks.h"

namespace Xj {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	void Xj::Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$" );
		s_CoreLogger = spdlog::stdout_color_mt("Engine");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("Game");
		s_CoreLogger->set_level(spdlog::level::trace);

	}
}