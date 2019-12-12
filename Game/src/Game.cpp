// Frank (10) precompile headers
// Frank (11) Create Window
// Frank (12) Key and Mouse Events
// Farnk (13) Layers

#include "Xj.h"
#include <Core\Application.h>

class Game : public Xj::Application {
public:
	Game() {}
	~Game(){}
	
};


Xj::Application* Xj::CreateApplication() {
	return new Game();
}