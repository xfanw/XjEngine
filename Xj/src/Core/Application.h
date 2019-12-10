#pragma once


#include "Core/Core.h"
#include "Events/ApplicationEvent.h"
#include "Core/Log.h"
#include "Window.h"


namespace Xj {
	class  XJ_API  Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		// Frank (12)
		void OnEvent(Event& e);
		// Frank (12)
	private:
		bool OnWindowClosed(WindowCloseEvent & e);
	//Frank (11)
	private:
		

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

