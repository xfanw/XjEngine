#include "xjpch.h"
#include "Application.h"
#include "GLFW/glfw3.h"

namespace Xj {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
	Application* Application::s_Instance = nullptr;
	Application::Application()
	{

		XJ_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		// Frank (22)
		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClosed));
		//XJ_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.Handled())
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	bool Application::OnWindowClosed(WindowCloseEvent& /*e*/)
	{
		m_Running = false;
		return true;
	}

	void Application::Run() {

		while (m_Running) {
			glClearColor(0.1, 0.1, 0.1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate();
				m_ImGuiLayer->Begin();
				for (Layer* layer_2 : m_LayerStack)
					layer_2->OnImGuiRender();
				m_ImGuiLayer->End();

				

			}
			// Frank (20) --
			//auto [x, y] = Input::GetMousePosition();
			//XJ_CORE_TRACE("{0},{1}", x, y);


			m_Window->OnUpdate();
			
		}
	}

}