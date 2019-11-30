#pragma once

// Frank (5.1)
#ifdef XJ_PLATFORM_WINDOWS
extern Xj::Application* Xj::CreateApplication();
	int main(int argc , char** argv) {
		printf("Hello!");
		auto app = Xj::CreateApplication();
		app->Run();
		delete app;
	}
	#else
	#error Hazel only supports Windows!
#endif