// Frank (17) GitHub
// Frank (18) GitHub pull request
// Frank (19) Input Polling
#include "Xj.h"
#include <Core\Application.h>

// TEMP
class ExampleLayer : public Xj::Layer {
public:
	ExampleLayer() :Layer("Example") {}

	void OnUpdate() override {
		XJ_INFO("ExampleLayer::Update");
	}
	void OnEvent(Xj::Event& event) override {
		XJ_FATAL("{0}", event);
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