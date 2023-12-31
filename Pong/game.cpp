#include "game.h"

void Game::init()
{
	createWindow();
	setGameMode(MENU);
	centeredStrings();
}

void Game::run()
{
	while (!WindowShouldClose())
	{
		switch (getGameMode())
		{
		case MENU:
			menu();
			break;
		case SINGLEPLAYER:
			singlePlayer();
			break;
		case MULTIPLAYER:
			multiPlayer();
			break;
		case END:
			end();
			break;
		default:
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
	while (!WindowShouldClose() && getGameMode() == MENU)
	{
		leftScore = 0;
		rightScore = 0;

		if (IsKeyPressed(KEY_ONE))
		{
			setGameMode(SINGLEPLAYER);
		}

		if (IsKeyPressed(KEY_TWO))
		{
			setGameMode(MULTIPLAYER);
		}

		BeginDrawing();

		ClearBackground(BLACK);

		DrawText("PONG", (GetScreenWidth() - pongStringSize) / 2, 200, 100, GREEN);
		DrawText("[1] Single Player", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2, 23, GREEN);
		DrawText("[2] Multi Player", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 + 30, 23, GREEN);
		DrawText("[DEL] Quit", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 + 90, 23, LIME);

		DrawText("MENU", (GetScreenWidth() - menuStringSize) / 2, 25, 23, RAYWHITE);

		EndDrawing();
	}
}

void Game::singlePlayer()
{
	Ball ball(GetScreenWidth() / 2, GetScreenHeight() / 2, -1, 0);

	LeftPaddle leftPaddle(30, GetScreenHeight() / 2 - 50);

	RightPaddle rightPaddle(GetScreenWidth() - 50, GetScreenHeight() / 2 - 50);

	while (!WindowShouldClose() && getGameMode() == SINGLEPLAYER)
	{
		if (IsKeyPressed(KEY_ESCAPE) && getGameMode() != MENU)
		{
			setGameMode(MENU);
			reset(ball, leftPaddle, rightPaddle);
		}

		checkForWinner();

		leftPaddle.collide(ball);
		leftPaddle.moveUp(KEY_W);
		leftPaddle.moveDown(KEY_S);

		ball.move();
		ball.collide();

		rightPaddle.collide(ball);
		bot(ball, rightPaddle);

		scoreLeft(ball, leftPaddle, rightPaddle);
		scoreRight(ball, leftPaddle, rightPaddle);


		BeginDrawing();

			ClearBackground(BLACK);

			leftPaddle.draw();
			ball.draw();
			rightPaddle.draw();

			DrawText("SINGLEPLAYER", (GetScreenWidth() - singlePlayerStringSize) / 2, 25, 23, RAYWHITE);
			DrawText("[DEL] Quit", GetScreenWidth() - quitStringSize - 20, 10, 20, LIME);

			displayScore();

			DrawFPS(10, 10);

		EndDrawing();
	}
}

void Game::multiPlayer()
{
	Ball ball(GetScreenWidth() / 2, GetScreenHeight() / 2, 1, 0);

	LeftPaddle leftPaddle(30, GetScreenHeight() / 2 - 50);

	RightPaddle rightPaddle(GetScreenWidth() - 50, GetScreenHeight() / 2 - 50);

	while (!WindowShouldClose() && getGameMode() == MULTIPLAYER)
	{
		if (IsKeyPressed(KEY_ESCAPE) && getGameMode() != MENU)
		{
			setGameMode(MENU);
			reset(ball, leftPaddle, rightPaddle);
		}

		checkForWinner();

		leftPaddle.collide(ball);
		leftPaddle.moveUp(KEY_W);
		leftPaddle.moveDown(KEY_S);

		ball.move();
		ball.collide();

		rightPaddle.collide(ball);
		rightPaddle.moveUp(KEY_UP);
		rightPaddle.moveDown(KEY_DOWN);

		scoreLeft(ball, leftPaddle, rightPaddle);
		scoreRight(ball, leftPaddle, rightPaddle);


		BeginDrawing();

		ClearBackground(BLACK);

			leftPaddle.draw();
			ball.draw();
			rightPaddle.draw();

			DrawText("MULTIPLAYER", (GetScreenWidth() - multiPlayerStringSize) / 2, 25, 23, RAYWHITE);
			DrawText("[DEL] Quit", GetScreenWidth() - quitStringSize - 20, 10, 20, LIME);

			displayScore();

			DrawFPS(10, 10);

		EndDrawing();
	}
}

void Game::end()
{
	while (!WindowShouldClose() && getGameMode() == END)
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			setGameMode(MENU);
		}

		if (IsKeyPressed(KEY_ONE))
		{
			setGameMode(SINGLEPLAYER);
		}

		if (IsKeyPressed(KEY_TWO))
		{
			setGameMode(MULTIPLAYER);
		}

		winText = winnerName + " Won!";


		BeginDrawing();

			ClearBackground(BLACK);

			DrawText(winText.c_str(), (GetScreenWidth() - MeasureText(winText.c_str(), 23)) / 2, 70, 23, RAYWHITE);
			
			DrawText("GAME OVER", (GetScreenWidth() - gameOverStringSize) / 2, 200, 100, GREEN);
			DrawText("[1] Single Player", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2, 23, GREEN);
			DrawText("[2] Multi Player", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 + 30, 23, GREEN);
			DrawText("[ESC] Menu", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 + 90, 23, LIME);
			DrawText("[DEL] Quit", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 + 120, 23, LIME);

		EndDrawing();
	}
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
	std::string leftScoreString = std::to_string(leftScore), rightScoreString = std::to_string(rightScore);

	DrawText(rightScoreString.c_str(), (GetScreenWidth() / 4) * 3, 25, 25, RAYWHITE);

	DrawText(leftScoreString.c_str(), GetScreenWidth() / 4, 25, 25, RAYWHITE);
}

void Game::reset(Ball& ball, LeftPaddle& leftPaddle, RightPaddle& rightPaddle)
{
	leftPaddle.reset(30, GetScreenHeight() / 2 - 50);
	ball.reset(GetScreenWidth() / 2, GetScreenHeight() / 2, -ball.xVel, 0);
	rightPaddle.reset(GetScreenWidth() - 50, GetScreenHeight() / 2 - 50);
}

void Game::createWindow()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_FULLSCREEN_MODE);

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

void Game::bot(Ball& ball, Paddle& paddle)
{
	// Follow the balls y position
	if (paddle.paddleRec.y > 0 && (paddle.paddleRec.y + paddle.height) < GetScreenHeight())
	{
		if (ball.ballRec.y > paddle.paddleRec.y + (paddle.height / 2))
		{
			paddle.paddleRec.y += GetFrameTime() * paddle.speed * 1.1;
		}
		
		if (ball.ballRec.y < paddle.paddleRec.y + (paddle.height / 2))
		{
			paddle.paddleRec.y -= GetFrameTime() * paddle.speed * 1.1;
		}
	}
	else if(paddle.paddleRec.y < 0)
	{
		paddle.paddleRec.y += GetFrameTime() * paddle.speed * 1.1;
	}
	else if ((paddle.paddleRec.y + paddle.height) > GetScreenHeight())
	{
		paddle.paddleRec.y -= GetFrameTime() * paddle.speed * 1.1;
	}
}