#pragma once
// Raylib
#include <raylib.h>

// Standard libraries
#include <iostream>
#include <string>

// Custom headers
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
	void createWindow();
	void init();
	void run();
	void stop();
	
	void setGameMode(GameMode mode);
	GameMode getGameMode();
	
	void menu();
	void singlePlayer(Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle);
	void multiPlayer(Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle);
	void bot(Ball& ball, Paddle& paddle);

	// Increment score
	void rightSideScored(Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle);
	void leftSideScored(Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle);

	void checkForWinner();
	void end();
	void reset(Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle);
	void displayScore();

	void calculateStringLengths();
private:
	int leftScore = 0, rightScore = 0, maxScore = 3;

	std::string winnerName;
	std::string winText;

	int pongStringSize, menuStringSize, singlePlayerStringSize, multiPlayerStringSize, gameOverStringSize, quitStringSize;

	GameMode currentGameMode;
};