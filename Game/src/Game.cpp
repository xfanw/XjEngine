// Frank (10) precompile headers
// Frank (11) Create Window
// Frank (12) Key and Mouse Events
// Farnk (13) Layers
// Frank (14) Glad, premake

#include "Xj.h"
#include <Core\Application.h>

// Frank(13) Example
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
		//Frank (13)
		PushLayer(new ExampleLayer());
	}
	~Game(){}
	
};


Xj::Application* Xj::CreateApplication() {
	return new Game();
}