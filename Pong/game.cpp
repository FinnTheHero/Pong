#include "game.h"

void Game::init()
{
	createWindow();
	setGameMode(MENU);
	centeredStrings();
}

void Game::run()
{
	Ball ball;

	LeftPaddle leftPaddle(30, GetScreenHeight() / 2 - 50);

	RightPaddle rightPaddle(GetScreenWidth() - 50, GetScreenHeight() / 2 - 50);

	// Main loop
	while (!WindowShouldClose())
	{
		if (IsKeyPressed(KEY_ESCAPE) && getGameMode() != MENU)
		{
			setGameMode(MENU);

			reset(ball, leftPaddle, rightPaddle);
		}


		switch (getGameMode())
		{
		case MENU:
			menu();
			break;
		case MULTIPLAYER:
			multiPlayer(ball, leftPaddle, rightPaddle);
			break;
		case SINGLEPLAYER:
			singlePlayer(ball, leftPaddle, rightPaddle);
			break;
		case END:
			end();
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
		setGameMode(SINGLEPLAYER);
	}*/

	if (IsKeyPressed(KEY_TWO))
	{
		setGameMode(MULTIPLAYER);
	}

	BeginDrawing();

	ClearBackground(BLACK);

	DrawText("PONG", (GetScreenWidth() - pongStringSize) / 2, 200, 100, GREEN);
	DrawText("[1] Single Player - Locked", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2, 23, DARKGRAY);
	DrawText("[2] Multi Player", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 + 30, 23, GREEN);
	DrawText("[DEL] Quit", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 + 90, 23, LIME);

	DrawText("MENU", (GetScreenWidth() - menuStringSize) / 2, 25, 23, RAYWHITE);

	EndDrawing();

}

void Game::singlePlayer(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle)
{
	checkForWinner();

	leftPaddle.collide(ball);
	leftPaddle.moveUp();
	leftPaddle.moveDown();

	ball.move();
	ball.collide();

	rightPaddle.collide(ball);
	rightPaddle.moveUp();
	rightPaddle.moveDown();

	scoreLeft(ball, leftPaddle, rightPaddle);
	scoreRight(ball, leftPaddle, rightPaddle);

	BeginDrawing();

	ClearBackground(BLACK);

	leftPaddle.draw(leftPaddle.leftPaddleRec);
	ball.draw();
	rightPaddle.draw(rightPaddle.rightPaddleRec);

	DrawText("SINGLEPLAYER", (GetScreenWidth() - singlePlayerStringSize) / 2, 25, 23, RAYWHITE);
	DrawText("[DEL] Quit", GetScreenWidth() - quitStringSize - 20, 10, 20, LIME);

	displayScore();

	DrawFPS(10, 10);

	EndDrawing();
}

void Game::multiPlayer(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle)
{
	checkForWinner();

	leftPaddle.collide(ball);
	leftPaddle.moveUp();
	leftPaddle.moveDown();

	ball.move();
	ball.collide();

	rightPaddle.collide(ball);
	rightPaddle.moveUp();
	rightPaddle.moveDown();

	scoreLeft(ball, leftPaddle, rightPaddle);
	scoreRight(ball, leftPaddle, rightPaddle);

	BeginDrawing();

	ClearBackground(BLACK);

	leftPaddle.draw(leftPaddle.leftPaddleRec);
	ball.draw();
	rightPaddle.draw(rightPaddle.rightPaddleRec);

	DrawText("MULTIPLAYER", (GetScreenWidth() - multiPlayerStringSize) / 2, 25, 23, RAYWHITE);
	DrawText("[DEL] Quit", GetScreenWidth() - quitStringSize - 20, 10, 20, LIME);

	displayScore();

	DrawFPS(10, 10);

	EndDrawing();
}

void Game::end()
{
	/*if (IsKeyPressed(KEY_ONE))
	{
		setGameMode(SINGLEPLAYER);
	}*/

	if (IsKeyPressed(KEY_TWO))
	{
		setGameMode(MULTIPLAYER);
	}

	winText = winnerName + " Won!";


	BeginDrawing();

	ClearBackground(BLACK);

	DrawText("GAME OVER", (GetScreenWidth() - gameOverStringSize) / 2, 200, 100, GREEN);
	DrawText("[1] Single Player - Locked", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2, 23, DARKGRAY);
	DrawText("[2] Multi Player", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 + 30, 23, GREEN);
	DrawText("[DEL] Quit", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 + 90, 23, LIME);

	DrawText(winText.c_str(), (GetScreenWidth() - MeasureText(winText.c_str(), 23)) / 2, 70, 23, RAYWHITE);

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
	if (ball.ballRec.x <= 0)
	{
		reset(ball, leftPaddle, rightPaddle);
		rightScore += 1;
	}
}

// Left side scored
void Game::scoreRight(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle)
{
	if (ball.ballRec.x >= GetScreenWidth())
	{
		reset(ball, leftPaddle, rightPaddle);
		leftScore += 1;
	}
}

void Game::checkForWinner()
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
	std::string leftScoreString = std::to_string(leftScore), rightScoreString = std::to_string(rightScore);

	// left side score
	DrawText(rightScoreString.c_str(), (GetScreenWidth() / 4) * 3, 25, 25, RAYWHITE);

	// Right side score
	DrawText(leftScoreString.c_str(), GetScreenWidth() / 4, 25, 25, RAYWHITE);
}

void Game::reset(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle)
{
	leftPaddle.reset(30, GetScreenHeight() / 2 - 50);
	ball.reset(GetScreenWidth() / 2, GetScreenHeight() / 2);
	rightPaddle.reset(GetScreenWidth() - 50, GetScreenHeight() / 2 - 50);
}

void Game::createWindow()
{
	// Adjust the window states
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_FULLSCREEN_MODE);

	// Create the window
	InitWindow(0, 0, "Pong");

	HideCursor();

	SetExitKey(KEY_DELETE);
}

void Game::centeredStrings()
{
	pongStringSize = MeasureText("PONG", 100);
	menuStringSize = MeasureText("MENU", 23);
	singlePlayerStringSize = MeasureText("SINGLEPLAYER", 23);
	multiPlayerStringSize = MeasureText("MULTIPLAYER", 23);
	gameOverStringSize = MeasureText("GAME OVER", 100);
	quitStringSize = MeasureText("[DEL] Quit", 20);
}