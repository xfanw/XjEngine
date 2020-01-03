
// Frank (32) Abstract VA
// Frank (33) Renderer


#include "Xj.h"
#include <Core\Application.h>

#include "imgui.h"



// TEMP
class ExampleLayer : public Xj::Layer {
public:
	ExampleLayer() :Layer("Example") {}

	void OnUpdate() override {
		if (Xj::Input::IsKeyPressed(XJ_KEY_TAB))
				XJ_INFO("Tab Key is pressed (poll)");
	}
	void OnEvent(Xj::Event& event) override {

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