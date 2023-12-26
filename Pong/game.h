#pragma once
// Raylib
#include <raylib.h>

// Standard libraries
#include <iostream>
#include <string>

// Custom headers
#include "window.h"
#include "ball.h"
#include "paddle.h"


enum GameMode {
	MENU,
	SINGLEPLAYER,
	MULTIPLAYER,
	END
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
	void scoreLeft(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle);
	void scoreRight(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle);
	void checkWinner();
	void end();
	void reset(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle);
	void displayScore();
private:
	// Player scores
	int leftScore = 0, rightScore = 0, maxScore = 3;

	// winner name
	std::string winnerName = "";

	// Current game mode
	GameMode currentGameMode = MENU;
};