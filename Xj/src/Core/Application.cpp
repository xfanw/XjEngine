#include "xjpch.h"
#include "Application.h"


#include "glad/glad.h"
#include "GLFW/glfw3.h"
namespace Xj {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
	Application* Application::s_Instance = nullptr;

	static GLenum ShaderDataToOpenGL(ShaderDataType type) {
		switch (type) {
		case ShaderDataType::Float: return GL_FLOAT;
		case ShaderDataType::Float2: return GL_FLOAT;
		case ShaderDataType::Float3: return GL_FLOAT;
		case ShaderDataType::Float4: return GL_FLOAT;
		case ShaderDataType::Mat3: return GL_FLOAT;
		case ShaderDataType::Mat4: return GL_FLOAT;
		case ShaderDataType::Int: return GL_INT;
		case ShaderDataType::Int2: return GL_INT;
		case ShaderDataType::Int3: return GL_INT;
		case ShaderDataType::Int4: return GL_INT;
		case ShaderDataType::Bool: return GL_BOOL;
		}
		return 0;
	}
	Application::Application()
	{

		XJ_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));


		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

		// Frank (28)

		// Vertex Array
		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);

		// Frank (30) --
		//// Vertex Buffer
		//glGenBuffers(1, &m_VertexBuffer);
		//glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);	

		// load data
		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 0.8f,
			 0.5f, -0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 0.8f,
			 0.0f,  0.5f, 0.0f, 0.2f, 0.8f, 0.8f, 0.8f
		};
		// glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


		// Frank (30) ++
		m_VertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
		//m_VertexBuffer->Bind();

		// Frank (31) --
		//glEnableVertexAttribArray(0);
		//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
		// Frank (31)
		BufferLayout layout = {
			{ShaderDataType::Float3, "a_position" }
			,{ShaderDataType::Float4,"a_Color" }
			//,{ShaderDataType::Float2,"a_TexCoord" }
			//,{ShaderDataType::Float3,"a_Normal" }
		};
		//m_VertexBuffer->SetLayout();
		uint32_t index = 0;
		for (const auto& element : layout) {
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, element.GetElementCout(),
				ShaderDataToOpenGL(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			index++;
		}



		// Frank (30) --
		//// Index Buffer
		//glGenBuffers(1, &m_IndexBuffer);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
		uint32_t indices[3] = { 0,1,2 };
		// Frank (30) ++
		m_IndexBuffer.reset(IndexBuffer::Create(indices, 3));
		//m_IndexBuffer->Bind();

		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

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

		m_Shader.reset(new Shader(vertexScr, fragmentScr));

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
			glClearColor(0.1f, 0.1f, 0.1f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Shader->Bind();
			glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate();
				m_ImGuiLayer->Begin();
				for (Layer* layer_2 : m_LayerStack)
					layer_2->OnImGuiRender();
				m_ImGuiLayer->End();



			}

			m_Window->OnUpdate();

		}
	}

}