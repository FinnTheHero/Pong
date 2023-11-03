#include "paddle.h"

void Paddle::draw()
{
	DrawRectangle(this->x, this->y, this->width, this->height, GREEN);
}

void Paddle::move()
{
	if (IsKeyDown(KEY_W) && this->y > 0)
	{
		this->y -= GetFrameTime() * this->speed;
	}

	if (IsKeyDown(KEY_S) && this->y + this->height < GetScreenHeight())
	{
		this->y += GetFrameTime() * this->speed;
	}
}

void Paddle::collide(Ball& ball)
{
	if (ball.x <= this->x + this->width)
	{
		ball.xVel = -ball.xVel;
	}

	/*if (ball.x + ball.width >= this->x - )
	{
		ball.xVel = -ball.xVel;
	}*/
}
