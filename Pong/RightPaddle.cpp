#include "paddle.h"

RightPaddle::RightPaddle(float x, float y) : Paddle(x, y) {}

void RightPaddle::collide(Ball& ball)
{
	if (CheckCollisionRecs(rightPaddleRec, ball.ballRec))
	{
		if (ball.xVel > 0)
		{
			ball.xVel = -ball.xVel;
			ball.speedUp();
		}

		std::srand(static_cast<unsigned int>(std::time(0)));
		if (ball.yVel < 0.0f) {
			// If ball is going up
			ball.yVel = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (-0.8f - -0.2f));
		}
		else {
			// If ball is going down or stationary
			ball.yVel = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (0.8f - 0.2f));
		}
	}
}

void RightPaddle::moveUp()
{
	if (IsKeyDown(KEY_UP) && rightPaddleRec.y > 0)
	{
		rightPaddleRec.y -= GetFrameTime() * this->speed * 1.1;
		speedUp();
	}
}

void RightPaddle::moveDown()
{
	if (IsKeyDown(KEY_DOWN) && rightPaddleRec.y + rightPaddleRec.height < GetScreenHeight())
	{
		rightPaddleRec.y += GetFrameTime() * this->speed * 1.1;
		speedUp();
	}
}

void RightPaddle::reset(float x, float y)
{
	if (this->speed - (this->speed / 2) > 350)
	{
		this->speed = this->speed / 2;
	}

	rightPaddleRec.x = x;
	rightPaddleRec.y = y;
}