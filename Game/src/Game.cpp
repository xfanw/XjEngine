


#include "Xj.h"

class Game : public Xj::Application {
public:
	Game() {}
	~Game(){}
	
};


Xj::Application* Xj::CreateApplication() {
	return new Game();
}