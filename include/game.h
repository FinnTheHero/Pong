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
	void singlePlayer();
	void multiPlayer();
	void bot(Ball& ball, Paddle& paddle);

	// Add score to the player who scored
	void scoreLeft(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle);
	void scoreRight(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle);

	void checkForWinner();
	void end();
	void reset(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle);
	void displayScore();

	void centeredStrings();
private:
	int leftScore = 0, rightScore = 0, maxScore = 3;

	std::string winnerName;
	std::string winText;

	int pongStringSize, menuStringSize, singlePlayerStringSize, multiPlayerStringSize, gameOverStringSize, quitStringSize;

	GameMode currentGameMode;
};