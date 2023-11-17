#include "paddle.h"

// Left paddle constructor
LeftPaddle::LeftPaddle(float x, float y) : Paddle(x, y) {}

// Collide ball
void LeftPaddle::collide(Ball& ball)
{
	if (CheckCollisionRecs(LeftPaddle::leftPaddleRec, ball.ballRec))
	{
		ball.xVel = -ball.xVel;
		/*
		// Calculate the center of the ball
		float ballCenterY = ball.y + ball.height / 2.0;

		// Calculate the center of the paddle
		float paddleCenterY = LeftPaddle::leftPaddleRec.y + LeftPaddle::leftPaddleRec.height / 2.0;

		// Calculate the relative position of the ball's center compared to the paddle's center
		float relativePosition = ballCenterY - paddleCenterY;

		// Adjust the Y velocity based on the relative position
		float newYVel = relativePosition / (LeftPaddle::leftPaddleRec.height / 2.0);
		ball.yVel = std::min(std::max(newYVel, -0.9f), 0.9f);*/
	}
}

void LeftPaddle::moveUp()
{
	if (IsKeyDown(KEY_W) && LeftPaddle::leftPaddleRec.y > 0)
	{
		LeftPaddle::leftPaddleRec.y -= GetFrameTime() * this->speed;
	}
}

void LeftPaddle::moveDown()
{
	if (IsKeyDown(KEY_S) && LeftPaddle::leftPaddleRec.y + LeftPaddle::leftPaddleRec.height < GetScreenHeight())
	{
		LeftPaddle::leftPaddleRec.y += GetFrameTime() * this->speed;
	}
}

void LeftPaddle::reset(float x, float y)
{
	LeftPaddle::leftPaddleRec.x = x;
	LeftPaddle::leftPaddleRec.y = y;
}