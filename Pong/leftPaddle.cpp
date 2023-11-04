#include "paddle.h"

// Left paddle constructor
LeftPaddle::LeftPaddle(int x, int y) : Paddle(x, y) {}

// Collide ball
void LeftPaddle::collide(Ball& ball)
{
	if (ball.x <= this->x + this->width)
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

void LeftPaddle::moveUp()
{
	if (IsKeyDown(KEY_W) && this->y > 0)
	{
		this->y -= GetFrameTime() * this->speed;
	}
}

void LeftPaddle::moveDown()
{
	if (IsKeyDown(KEY_S) && this->y + this->height < GetScreenHeight())
	{
		this->y += GetFrameTime() * this->speed;
	}
}