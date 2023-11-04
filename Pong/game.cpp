#include "game.h"

void Game::init()
{
	createWindow();
	Game::setGameMode(MULTIPLAYER);
}

void Game::run()
{
	// Create ball object
	Ball ball;

	// Create left paddle object
	LeftPaddle leftPaddle(30, GetScreenHeight() / 2);

	// Create right paddle object
	RightPaddle RightPaddle(GetScreenWidth() - 50, GetScreenHeight() / 2);

	// Main loop
	while (!WindowShouldClose())
	{
		BeginDrawing();

		// Set background to white
		ClearBackground(BLACK);

		switch (getGameMode())
		{
		case MENU:
			Game::menu();
			break;
		case MULTIPLAYER:
			Game::multiPlayer(ball, leftPaddle, RightPaddle);
			break;
		case SINGLEPLAYER:
			Game::singlePlayer(ball, leftPaddle, RightPaddle);
			break;
		}

		EndDrawing();
	}
}

void Game::stop()
{
	CloseWindow();
}

void Game::menu()
{

}

void Game::singlePlayer(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle)
{
	// Ball methods
	ball.draw();
	ball.move();
	ball.collide();

	// Left paddle methods
	leftPaddle.collide(ball);
	leftPaddle.draw();
	leftPaddle.moveUp();
	leftPaddle.moveDown();

	// Right paddle methods
	rightPaddle.collide(ball);
	rightPaddle.draw();
	rightPaddle.moveUp();
	rightPaddle.moveDown();

	// Draw FPS in top left corner
	DrawFPS(10, 10);
}

void Game::multiPlayer(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle)
{
	// Ball methods
	ball.draw();
	ball.move();
	ball.collide();

	// Left paddle methods
	leftPaddle.collide(ball);
	leftPaddle.draw();
	leftPaddle.moveUp();
	leftPaddle.moveDown();

	// Right paddle methods
	rightPaddle.collide(ball);
	rightPaddle.draw();
	rightPaddle.moveUp();
	rightPaddle.moveDown();

	// Draw FPS in top left corner
	DrawFPS(10, 10);
}

void Game::setGameMode(GameMode mode)
{
	currentGameMode = mode;
}

GameMode Game::getGameMode()
{
	return currentGameMode;
}

void Game::scoreLeft(Ball& ball)
{
}

void Game::scoreRight(Ball& ball)
{
}