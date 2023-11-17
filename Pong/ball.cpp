#include "ball.h"

void Ball::draw()
{
	DrawRectangleRec(Ball::ballRec, GREEN);
}

void Ball::move()
{
    // Update the ball's position based on the velocity components
    Ball::ballRec.x += this->xVel * GetFrameTime() * this->speed;
    Ball::ballRec.y += this->yVel * GetFrameTime() * this->speed;
}

void Ball::collide()
{
    // Collide bottom
    if (Ball::ballRec.y+ Ball::ballRec.height >= GetScreenHeight())
    {
        this->yVel = -this->yVel;
    }

    // Colide top
    if (Ball::ballRec.y <= 0)
    {
        this->yVel = -this->yVel;
    }
}