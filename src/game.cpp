#include "../include/game.h"

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
	RightPaddle rightPaddle(GetScreenWidth() - 50, GetScreenHeight() / 2 - 50);

	// Main loop
	while (!WindowShouldClose())
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			// Get back to menu
			Game::setGameMode(MENU);
			
			Game::reset(ball, leftPaddle, rightPaddle);
		}


		switch (getGameMode())
		{
		case MENU:
			Game::menu();
			break;
		case MULTIPLAYER:
			Game::multiPlayer(ball, leftPaddle, rightPaddle);
			break;
		case SINGLEPLAYER:
			Game::singlePlayer(ball, leftPaddle, rightPaddle);
			break;
		case END:
			Game::end();
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

	/*if (IsKeyPressed(KEY_ONE))
	{
		Game::setGameMode(SINGLEPLAYER);
	}*/

	if (IsKeyPressed(KEY_TWO))
	{
		Game::setGameMode(MULTIPLAYER);
	}

    BeginDrawing();

	// Set background to white
	ClearBackground(BLACK);

	// Draw options
	DrawText("PONG", GetScreenWidth() / 2 - 130, 200, 100, GREEN);
	DrawText("[1] Single Player - Locked", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2, 23, DARKGRAY);
	DrawText("[2] Multi Player", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 + 30, 23, GREEN);
	DrawText("[DEL] Quit", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 + 90, 23, LIME);
	
	// Draw game mode
	DrawText("MENU", GetScreenWidth() / 2 - 30, 25, 23, RAYWHITE);

	EndDrawing();

}

void Game::singlePlayer(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle)
{
	// Check for winner
	Game::checkWinner();

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

	// Wait for goal
	Game::scoreLeft(ball, leftPaddle, rightPaddle);
	Game::scoreRight(ball, leftPaddle, rightPaddle);
	
	BeginDrawing();

	// Set background to white
	ClearBackground(BLACK);

	leftPaddle.draw(leftPaddle.leftPaddleRec);
	
	ball.draw();

	rightPaddle.draw(rightPaddle.rightPaddleRec);

	// Draw game mode
	DrawText("SINGLEPLAYER", GetScreenWidth()/2 - 90, 25, 23, RAYWHITE);
	DrawText("[DEL] Quit", GetScreenWidth() - 110, 10, 20, LIME);
	
	// Draw score
	Game::displayScore();

	// Draw FPS in top left corner
	DrawFPS(10, 10);

	EndDrawing();
}

void Game::multiPlayer(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle)
{
	// Check for winner
	Game::checkWinner();

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

	// Wait for goal
	Game::scoreLeft(ball, leftPaddle, rightPaddle);
	Game::scoreRight(ball, leftPaddle, rightPaddle);

	BeginDrawing();

	// Set background to white
	ClearBackground(BLACK);

	leftPaddle.draw(leftPaddle.leftPaddleRec);

	ball.draw();

	rightPaddle.draw(rightPaddle.rightPaddleRec);

	// Draw game mode
	DrawText("MULTIPLAYER", GetScreenWidth() / 2 - 70, 25, 23, RAYWHITE);
	DrawText("[DEL] Quit", GetScreenWidth() - 110, 10, 20, LIME);

	// Draw score
	Game::displayScore();

	// Draw FPS in top left corner
	DrawFPS(10, 10);

	EndDrawing();
}

void Game::end()
{
	/*if (IsKeyPressed(KEY_ONE))
	{
		Game::setGameMode(SINGLEPLAYER);
	}*/

	if (IsKeyPressed(KEY_TWO))
	{
		Game::setGameMode(MULTIPLAYER);
	}

	BeginDrawing();

	// Set background to white
	ClearBackground(BLACK);

	// Draw options
	DrawText("GAME OVER", GetScreenWidth() / 2 - 300, 200, 100, GREEN);
	DrawText("[1] Single Player - Locked", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2, 23, DARKGRAY);
	DrawText("[2] Multi Player", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 + 30, 23, GREEN);
	DrawText("[DEL] Quit", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 + 90, 23, LIME);

	std::string winText = winnerName + " Won!";
	DrawText(winText.c_str(), GetScreenWidth() / 2 - 80, 70, 23, RAYWHITE);

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

// Right side scored
void Game::scoreLeft(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle)
{
	if (ball.ballRec.x <= 0 )
	{
		Game::reset(ball,leftPaddle,rightPaddle);
		rightScore += 1;
	}
}

// Left side scored
void Game::scoreRight(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle)
{
	if (ball.ballRec.x >= GetScreenWidth())
	{
		Game::reset(ball,leftPaddle,rightPaddle);
		leftScore += 1;
	}
}

// Check for win
void Game::checkWinner()
{
	if (leftScore == maxScore)
	{
		leftScore = 0;
		rightScore = 0;
		winnerName = "Left side";
		setGameMode(END);
	}
	
	if (rightScore == maxScore)
	{
		leftScore = 0;
		rightScore = 0;
		winnerName = "Right side";
		setGameMode(END);
	}
}

void Game::displayScore()
{
	// Convert score from int to string
	std::string leftScoreString = std::to_string(leftScore), rightScoreString = std::to_string(rightScore) ;

	// left side score
	DrawText(rightScoreString.c_str(), (GetScreenWidth() / 4) * 3 , 25, 25, RAYWHITE);

	// Right side score
	DrawText(leftScoreString.c_str(), GetScreenWidth() / 4, 25, 25, RAYWHITE);
}

void Game::reset(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle)
{
	// Reset ball and paddles
	leftPaddle.reset(30, GetScreenHeight() / 2 - 50);
	ball.reset(GetScreenWidth() / 2, GetScreenHeight() / 2);
	rightPaddle.reset(GetScreenWidth() - 50, GetScreenHeight() / 2 - 50);
}