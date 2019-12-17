#pragma once


#include "Core/Core.h"
#include "Events/ApplicationEvent.h"
#include "Core/Log.h"
#include "Window.h"
#include "Layer/LayerStack.h"
#include "Core/Input.h"

// Frank (22)
#include "ImGui/ImGuiLayer.h"
namespace Xj {
	class  XJ_API  Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClosed(WindowCloseEvent & e);

	private:
		// Fake Singleton
		static Application* s_Instance;

		std::unique_ptr<Window> m_Window;
		//Frank (22)
		ImGuiLayer* m_ImGuiLayer;

		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

