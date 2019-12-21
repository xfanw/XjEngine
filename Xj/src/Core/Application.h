#pragma once


#include "Core/Core.h"
#include "Core/Log.h"
#include "Core/Input.h"

#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "Layer/LayerStack.h"
#include "ImGui/ImGuiLayer.h"

// Frank (29)
#include "Renderer/Shader.h"
// Frank (30)
#include "Renderer/Buffer.h"


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
		ImGuiLayer* m_ImGuiLayer;

		bool m_Running = true;
		LayerStack m_LayerStack;

		// Frank (28)
		// Frank (30)--
		unsigned int m_VertexArray/*, m_VertexBuffer*//*, m_IndexBuffer*/;
		// Frank (29)
		std::unique_ptr<Shader> m_Shader;
		// Frank (30)
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;

	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

