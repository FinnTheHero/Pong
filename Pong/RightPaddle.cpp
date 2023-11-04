#include "paddle.h"

// Right paddle constructor
RightPaddle::RightPaddle(int x, int y) : Paddle(x,y) {}

// Collide ball
void RightPaddle::collide(Ball& ball)
{
	if (ball.x + ball.width >= this->x)
	{
		ball.xVel = -ball.xVel;
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