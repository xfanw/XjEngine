// Frank (10) precompile headers
// Frank (11) Create Window

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