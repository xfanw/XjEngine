#pragma once

// Frank (5.1)
#ifdef XJ_PLATFORM_WINDOWS
extern Xj::Application* Xj::CreateApplication();
	int main(int argc , char** argv) {

		//Frank (6)++
		Xj::Log::Init();
		//Frank (6.5)--
		//Xj::Log::GetCoreLogger()->warn("Initialized Log!");
		//Xj::Log::GetClientLogger()->info("Hello!");
		//Frank (6.5)++
		XJ_CORE_WARN("Initialized Log!");
		int a = 5;
		XJ_CLIENT_INFO("Hello! Var = {0}", a);


		printf("Hello!");
		auto app = Xj::CreateApplication();
		app->Run();
		delete app;
	}
	#else
	#error Hazel only supports Windows!
#endif