#include "xjpch.h"
#include "Application.h"
//Frank (11)
#include "GLFW/glfw3.h"

namespace Xj {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
	Application::Application()
	{
		//Frank (11)
		m_Window = std::unique_ptr<Window>(Window::Create());
		//Frank (12)
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	
	}

	Application::~Application()
	{

	}
	// Frank (12)
	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClosed));
		XJ_CORE_TRACE("{0}", e);
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
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