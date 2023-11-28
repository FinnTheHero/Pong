// Standard libraries
#include <iostream>

// Include Raylib
#include <raylib.h>

// Include game class
#include "../include/game.h"

int main(void) {
	Game game;
	
	game.init();
	game.run();
	game.stop();
	return 0;
}