#pragma once

#ifdef XJ_PLATFORM_WINDOWS
extern Xj::Application* Xj::CreateApplication();
	int main(int /*argc*/ , char** /*argv*/) {

		Xj::Log::Init();

		XJ_CORE_TRACE("Initialized Log!");
		int a = 5;
		XJ_INFO("Hello! Var = {0}", a);


		//printf("Hello!");
		auto app = Xj::CreateApplication();
		app->Run();
		delete app;
	}
	#else
	#error Hazel only supports Windows!
#endif