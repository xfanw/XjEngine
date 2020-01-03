#include "xjpch.h"
#include "Application.h"


//#include "glad/glad.h"
//#include "GLFW/glfw3.h"

#include "Renderer/Renderer.h"

// Frank (33)
namespace Xj {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{

		XJ_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));


		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);


		m_VertexArray.reset(VertexArray::Create());

		// load data
		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 0.8f,
			 0.5f, -0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 0.8f,
			 0.0f,  0.5f, 0.0f, 0.2f, 0.8f, 0.8f, 0.8f
		};

		m_VertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

		BufferLayout layout = {
			{ShaderDataType::Float3, "a_position" }
			,{ShaderDataType::Float4,"a_Color" }

		};
		m_VertexBuffer->SetLayout(layout);

		m_VertexArray->AddVertexBuffer(m_VertexBuffer);

		uint32_t indices[3] = { 0,1,2 };
		m_IndexBuffer.reset(IndexBuffer::Create(indices, 3));

		m_VertexArray->SetIndexBuffer(m_IndexBuffer);

		// Frank (32) Square
		m_SquareVertexArray.reset(VertexArray::Create());
		float squareVertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};
		m_SquareVertexBuffer.reset(VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		BufferLayout squareLayout = {
			{ShaderDataType::Float3, "a_position" }
		};
		m_SquareVertexBuffer->SetLayout(squareLayout);

		m_SquareVertexArray->AddVertexBuffer(m_SquareVertexBuffer);

		uint32_t squareIndices[6] = { 0,1,2,2,3,0};
		m_SquareIndexBuffer.reset(IndexBuffer::Create(squareIndices, 6));
		m_SquareVertexArray->SetIndexBuffer(m_SquareIndexBuffer);




		// Shader
		std::string vertexScr = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
			out vec3 v_Position;
			out vec4 v_Color;
			void main(){
				v_Position=a_Position * 0.5 + 0.5;
				gl_Position = vec4(a_Position , 1.0);
				v_Color = a_Color;
			}

		)";

		std::string fragmentScr = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			in vec4 v_Color;


			void main(){
				/*color = vec4(v_Position, 1.0);*/
				color = v_Color;
			}

		)";


		std::string vertexScr2 = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			out vec3 v_Position;

			void main(){
				v_Position=a_Position * 0.5 + 0.5;
				gl_Position = vec4(a_Position*1.5 , 1.0);

			}

		)";

		std::string fragmentScr2 = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			in vec3 v_Position;

			void main(){
				color = vec4(v_Position, 1.0);
			}

		)";
		m_Shader.reset(new Shader(vertexScr, fragmentScr));
		m_Shader2.reset(new Shader(vertexScr2, fragmentScr2));

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
			// Frank (33)--
			//glClearColor(0.1f, 0.1f, 0.1f, 1);
			//glClear(GL_COLOR_BUFFER_BIT);

			RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
			RenderCommand::Clear();


			Renderer::BeginScene();

			m_Shader2->Bind();
			Renderer::Submit(m_SquareVertexArray);

			m_Shader->Bind();
			Renderer::Submit(m_VertexArray);

			Renderer::EndScene();

			// Frank (33) --
			////Renderer::Flush();

			////m_Shader2->Bind();
			////m_SquareVertexArray->Bind();
			//glDrawElements(GL_TRIANGLES, m_SquareVertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

			////m_Shader->Bind();
			////m_VertexArray->Bind();
			//glDrawElements(GL_TRIANGLES, m_VertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate();
			}
			m_ImGuiLayer->Begin();
			for (Layer* layer_2 : m_LayerStack)
				layer_2->OnImGuiRender();
			m_ImGuiLayer->End();
			

			m_Window->OnUpdate();
		}
	}
}