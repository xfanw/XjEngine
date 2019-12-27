// Frank (27) Renderer Context
// Frank (28) Triangle
// Frank (20) Shader
// Frank (30) Renderer API
// Frank (31) 



#include "Xj.h"
#include <Core\Application.h>

#include "imgui.h"

//#include <glm/vec3.hpp> // glm::vec3
//#include <glm/vec4.hpp> // glm::vec4
//#include <glm/mat4x4.hpp> // glm::mat4
//#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
//#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
//
//
//glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
//{
//	glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
//	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
//	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
//	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
//	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
//	return Projection * View * Model;
//}

// TEMP
class ExampleLayer : public Xj::Layer {
public:
	ExampleLayer() :Layer("Example") {}

	void OnUpdate() override {
		if (Xj::Input::IsKeyPressed(XJ_KEY_TAB))
				XJ_INFO("Tab Key is pressed (poll)");
	}
	void OnEvent(Xj::Event& event) override {
		//XJ_FATAL("{0}", event);
		if (event.GetEventType() == Xj::EventType::KeyPressed) {
			Xj::KeyPressedEvent& e = (Xj::KeyPressedEvent&) event;
			XJ_INFO("{0}", (char)e.GetKeyCode());

			//TEST
			if (Xj::Input::IsKeyPressed(XJ_KEY_TAB))
				XJ_INFO("Tab Key is pressed (event)");
		}
	}
	virtual void OnImGuiRender() override {
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

};



class Game : public Xj::Application {
public:
	Game() {
		PushLayer(new ExampleLayer());
		// PushOverlay(new Xj::ImGuiLayer());
	}
	~Game(){}
	
};


Xj::Application* Xj::CreateApplication() {
	return new Game();
}