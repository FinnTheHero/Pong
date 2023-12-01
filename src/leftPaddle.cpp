#include "../include/paddle.h"

// Left paddle constructor
LeftPaddle::LeftPaddle(float x, float y) : Paddle(x, y) {}

// Collide ball
void LeftPaddle::collide(Ball& ball)
{
	if (CheckCollisionRecs(LeftPaddle::leftPaddleRec, ball.ballRec))
	{
		if (ball.xVel < 0)
		{
			ball.xVel = -ball.xVel;
			ball.speedUp();
		}

		std::srand(std::time(NULL));
		ball.yVel = -0.9f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (2.0f * 0.9f)));
	}
}

void LeftPaddle::moveUp()
{
	if (IsKeyDown(KEY_W) && LeftPaddle::leftPaddleRec.y > 0)
	{
		LeftPaddle::leftPaddleRec.y -= GetFrameTime() * this->speed;
		LeftPaddle::speedUp();
	}
}

void LeftPaddle::moveDown()
{
	if (IsKeyDown(KEY_S) && LeftPaddle::leftPaddleRec.y + LeftPaddle::leftPaddleRec.height < GetScreenHeight())
	{
		LeftPaddle::leftPaddleRec.y += GetFrameTime() * this->speed;
		LeftPaddle::speedUp();
	}
}

void LeftPaddle::reset(float x, float y)
{
	if (this->speed - (this->speed / 2) > 350)
	{
		this->speed = this->speed / 2;
	}
	LeftPaddle::leftPaddleRec.x = x;
	LeftPaddle::leftPaddleRec.y = y;
}