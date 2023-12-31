#include "paddle.h"

LeftPaddle::LeftPaddle(float x, float y) : Paddle(x, y) {}

void LeftPaddle::collide(Ball& ball)
{
	if (CheckCollisionRecs(leftPaddleRec, ball.ballRec))
	{
		if (ball.xVel < 0)
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

void LeftPaddle::moveUp()
{
	if (IsKeyDown(KEY_W) && leftPaddleRec.y > 0)
	{
		leftPaddleRec.y -= GetFrameTime() * this->speed;
		speedUp();
	}
}

void LeftPaddle::moveDown()
{
	if (IsKeyDown(KEY_S) && leftPaddleRec.y + leftPaddleRec.height < GetScreenHeight())
	{
		leftPaddleRec.y += GetFrameTime() * this->speed;
		speedUp();
	}
}

void LeftPaddle::reset(float x, float y)
{
	if (this->speed - (this->speed / 2) > 350)
	{
		this->speed = this->speed / 2;
	}

	leftPaddleRec.x = x;
	leftPaddleRec.y = y;
}