#include "../include/paddle.h"

// Right paddle constructor
RightPaddle::RightPaddle(float x, float y) : Paddle(x,y) {}

// Collide ball
void RightPaddle::collide(Ball& ball)
{
	if (CheckCollisionRecs(RightPaddle::rightPaddleRec, ball.ballRec))
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
		} else {
			// If ball is going down or stationary
			ball.yVel = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (0.8f - 0.2f));
		}
	}
}

void RightPaddle::moveUp()
{
	if (IsKeyDown(KEY_UP) && RightPaddle::rightPaddleRec.y > 0)
	{
		RightPaddle::rightPaddleRec.y -= GetFrameTime() * this->speed * 1.1;
		RightPaddle::speedUp();
	}
}

void RightPaddle::moveDown()
{
	if (IsKeyDown(KEY_DOWN) && RightPaddle::rightPaddleRec.y + RightPaddle::rightPaddleRec.height < GetScreenHeight())
	{
		RightPaddle::rightPaddleRec.y += GetFrameTime() * this->speed * 1.1;
		RightPaddle::speedUp();
	}
}

void RightPaddle::reset(float x, float y)
{
	if (this->speed - (this->speed / 2) > 350)
	{
		this->speed = this->speed / 2;
	}
	RightPaddle::rightPaddleRec.x = x;
	RightPaddle::rightPaddleRec.y = y;
}