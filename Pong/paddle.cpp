#include "paddle.h"

Paddle::Paddle(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Paddle::draw()
{
	DrawRectangle(this->x, this->y, this->width, this->height, GREEN);
}
