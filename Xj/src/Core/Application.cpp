#include "Application.h"

namespace Xj {
	Application::Application()
	{
	}

	Application::~Application()
	{

	}

	void Application::Run() {
		WindowResizeEvent e(1200, 720);
		XJ_CORE_TRACE(e);
		while (true);
	}

}
