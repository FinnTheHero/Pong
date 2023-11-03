#include "ball.h"

void Ball::draw()
{
	DrawRectangle(this->x, this->y, this->width, this->height, GREEN);
}

void Ball::move()
{
    // Update the ball's position based on the velocity components
    this->x += this->xVel * GetFrameTime() * this->speed;
    this->y += this->yVel * GetFrameTime() * this->speed;
}

void Ball::collide()
{
    // Collide bottom
    if (this->y+this->height >= GetScreenHeight())
    {
        this->yVel = -this->yVel;
    }

    // Colide top
    if (this->y <= 0)
    {
        this->yVel = -this->yVel;
    }
}