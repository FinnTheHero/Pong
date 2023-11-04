#include "paddle.h"

// Left paddle constructor
LeftPaddle::LeftPaddle(int x, int y) : Paddle(x, y) {}

// Collide ball
void LeftPaddle::collide(Ball& ball)
{
	if (ball.x <= this->x + this->width)
	{
		ball.xVel = -ball.xVel;
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