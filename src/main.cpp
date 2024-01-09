// Standard libraries
#include <iostream>

// Custom headers
#include "game.h"


int main(void) {
	Game game;
	
	game.init();
	game.run();
	game.stop();

	return 0;
}