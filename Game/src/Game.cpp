// Frank (17) GitHub
// Frank (18) GitHub pull request
// Frank (19) Input Polling
// Frank (20) Key and Mouse Code


#include "Xj.h"
#include <Core\Application.h>

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

};


class Game : public Xj::Application {
public:
	Game() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Xj::ImGuiLayer());
	}
	~Game(){}
	
};


Xj::Application* Xj::CreateApplication() {
	return new Game();
}