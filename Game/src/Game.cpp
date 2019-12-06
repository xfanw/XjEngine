// Frank (4) Test
// Frank (5) Remove Test, add Core and Entry

// Frank (6) Logging include sdplog use macro function defination
// Frank (7) PreMake


#include "Xj.h"

class Game : public Xj::Application {
public:
	Game() {}
	~Game(){}
	
};

// Frank 5.1

//int main() {
//	Game* game = new Game();
//	game->Run();
//	delete game;
//}

// Frank(5.2)

Xj::Application* Xj::CreateApplication() {
	return new Game();
}