#include "../include/paddle.h"

Paddle::Paddle(float x, float y)
{
	this->x = x;
	this->y = y;
}


void Paddle::draw(Rectangle paddle)
{
	DrawRectangleRec(paddle, GREEN);
}

void Paddle::speedUp()
{
	if (this->speed < 600)
	{
		this->speed += 1;
	}
}