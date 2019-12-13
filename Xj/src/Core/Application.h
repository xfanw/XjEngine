#pragma once


#include "Core/Core.h"
#include "Events/ApplicationEvent.h"
#include "Core/Log.h"
#include "Window.h"
#include "Layer/LayerStack.h"

namespace Xj {
	class  XJ_API  Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		// Frank (12)
		void OnEvent(Event& e);

		// Frank (13) 
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);


		// Frank (15) 
		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
		// Frank (12)
	private:
		bool OnWindowClosed(WindowCloseEvent & e);
	//Frank (11)
	private:
		//Frank (15) add singleton
		static Application* s_Instance;

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		// Frank (13)
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

