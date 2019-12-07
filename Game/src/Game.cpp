


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