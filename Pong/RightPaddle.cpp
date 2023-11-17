#include "paddle.h"

// Right paddle constructor
RightPaddle::RightPaddle(float x, float y) : Paddle(x,y) {}

// Collide ball
void RightPaddle::collide(Ball& ball)
{
	if (CheckCollisionRecs(RightPaddle::rightPaddleRec, ball.ballRec))
	{
		ball.xVel = -ball.xVel;
		// Calculate the center of the ball
		float ballCenterY = ball.y + ball.height / 2.0;

		// Calculate the center of the paddle
		float paddleCenterY = RightPaddle::rightPaddleRec.y + RightPaddle::rightPaddleRec.height / 2.0;

		// Calculate the relative position of the ball's center compared to the paddle's center
		float relativePosition = ballCenterY - paddleCenterY;

		// Adjust the Y velocity based on the relative position
		float newYVel = relativePosition / (RightPaddle::rightPaddleRec.height / 2.0);
		ball.yVel = std::min(std::max(newYVel, -0.9f), 0.9f);
	}
}

void RightPaddle::moveUp()
{
	if (IsKeyDown(KEY_UP) && RightPaddle::rightPaddleRec.y > 0)
	{
		RightPaddle::rightPaddleRec.y -= GetFrameTime() * this->speed;
	}
}

void RightPaddle::moveDown()
{
	if (IsKeyDown(KEY_DOWN) && RightPaddle::rightPaddleRec.y + RightPaddle::rightPaddleRec.height < GetScreenHeight())
	{
		RightPaddle::rightPaddleRec.y += GetFrameTime() * this->speed;
	}
}