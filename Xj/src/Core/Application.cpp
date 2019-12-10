#include "xjpch.h"
#include "Application.h"
//Frank (11)
#include "GLFW/glfw3.h"

namespace Xj {
	Application::Application()
	{
		//Frank (11)
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run() {
		// Frank (11) --
		//WindowResizeEvent e(1200, 720);
		//XJ_CORE_TRACE(e);

		// Frank (11) ++
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

}