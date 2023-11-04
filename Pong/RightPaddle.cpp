#include "paddle.h"

// Right paddle constructor
RightPaddle::RightPaddle(int x, int y) : Paddle(x,y) {}

// Collide ball
void RightPaddle::collide(Ball& ball)
{
	if (ball.x + ball.width >= this->x)
	{
		ball.xVel = -ball.xVel;

		// Calculate the center of the ball
		float ballCenterY = ball.y + ball.height / 2.0;

		// Calculate the center of the paddle
		float paddleCenterY = this->y + this->height / 2.0;

		// Calculate the relative position of the ball's center compared to the paddle's center
		float relativePosition = ballCenterY - paddleCenterY;

		// Adjust the Y velocity based on the relative position
		float newYVel = relativePosition / (this->height / 2.0);
		ball.yVel = std::min(std::max(newYVel, -0.9f), 0.9f);
	}
}

void RightPaddle::moveUp()
{
	if (IsKeyDown(KEY_UP) && this->y > 0)
	{
		this->y -= GetFrameTime() * this->speed;
	}
}

void RightPaddle::moveDown()
{
	if (IsKeyDown(KEY_DOWN) && this->y + this->height < GetScreenHeight())
	{
		this->y += GetFrameTime() * this->speed;
	}
}