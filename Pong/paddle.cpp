#include "paddle.h"

Paddle::Paddle(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Paddle::draw(Rectangle paddle)
{
	DrawRectangleRec(paddle, GREEN);
}
