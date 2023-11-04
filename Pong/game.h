#pragma once
// Standard libraries
#include <iostream>

// Include Raylib
#include <raylib.h>

// Game files
#include "window.h"
#include "ball.h"
#include "paddle.h"

enum GameMode {
	MENU,
	SINGLEPLAYER,
	MULTIPLAYER
};

class Game
{
public:
	// Game methods
	void init();
	void run();
	void stop();
	void setGameMode(GameMode mode);
	GameMode getGameMode();
	void menu();
	void singlePlayer(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle);
	void multiPlayer(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle);
	void scoreLeft(Ball& ball);
	void scoreRight(Ball& ball);

private:
	// Player scores
	int player1 = 0, player2 = 0;

	// Current game mode
	GameMode currentGameMode;
};