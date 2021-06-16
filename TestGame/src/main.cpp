#include <Hunter.h>

//instead of calling main function we do this
class GameApp : public Hunter::HunterApp { //inherit from our game engine
	
};

START_GAME(GameApp) //use macro to start our game - game engine will supply this macro