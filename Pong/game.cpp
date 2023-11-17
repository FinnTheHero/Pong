#include "game.h"

void Game::init()
{
	createWindow();
	Game::setGameMode(MENU);
}

void Game::run()
{
	// Create ball object
	Ball ball;

	// Create left paddle object
	LeftPaddle leftPaddle(30, GetScreenHeight() / 2 - 50);

	// Create right paddle object
	RightPaddle RightPaddle(GetScreenWidth() - 50, GetScreenHeight() / 2 - 50);

	// Main loop
	while (!WindowShouldClose())
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			Game::setGameMode(MENU);
		}


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

	}
}

void Game::stop()
{
	CloseWindow();
}

void Game::menu()
{

	if (IsKeyPressed(KEY_ONE))
	{
		Game::setGameMode(SINGLEPLAYER);
	}

	if (IsKeyPressed(KEY_TWO))
	{
		Game::setGameMode(MULTIPLAYER);
	}

    BeginDrawing();

	// Set background to white
	ClearBackground(BLACK);

	// Draw options
	DrawText("[1] Single Player", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2, 23, GREEN);
	DrawText("[2] Multi Player", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 + 30, 23, GREEN);

	
	// Draw game mode
	DrawText("MENU", GetScreenWidth() / 2 - 30, 10, 23, RAYWHITE);

	EndDrawing();

}

void Game::singlePlayer(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle)
{
	// Left paddle methods
	leftPaddle.collide(ball);
	leftPaddle.moveUp();
	leftPaddle.moveDown();
	
	// Ball methods
	ball.move();
	ball.collide();

	// Right paddle methods
	rightPaddle.collide(ball);
	rightPaddle.moveUp();
	rightPaddle.moveDown();
	
	BeginDrawing();

	// Set background to white
	ClearBackground(BLACK);

	leftPaddle.draw(leftPaddle.leftPaddleRec);
	
	ball.draw();

	rightPaddle.draw(rightPaddle.rightPaddleRec);

	// Draw game mode
	DrawText("SINGLEPLAYER", GetScreenWidth()/2 - 70, 10, 23, RAYWHITE);

	// Draw FPS in top left corner
	DrawFPS(10, 10);

	EndDrawing();
}

void Game::multiPlayer(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle)
{
	// Left paddle methods
	leftPaddle.collide(ball);
	leftPaddle.moveUp();
	leftPaddle.moveDown();

	// Ball methods
	ball.move();
	ball.collide();

	// Right paddle methods
	rightPaddle.collide(ball);
	rightPaddle.moveUp();
	rightPaddle.moveDown();

	BeginDrawing();

	// Set background to white
	ClearBackground(BLACK);

	leftPaddle.draw(leftPaddle.leftPaddleRec);

	ball.draw();

	rightPaddle.draw(rightPaddle.rightPaddleRec);

	// Draw game mode
	DrawText("MULTIPLAYER", GetScreenWidth() / 2 - 70, 10, 23, RAYWHITE);

	// Draw FPS in top left corner
	DrawFPS(10, 10);

	EndDrawing();
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