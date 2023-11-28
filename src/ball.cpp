#include "../include/ball.h"

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

void Ball::reset(float x, float y)
{
    Ball::ballRec.x = x;
    Ball::ballRec.y = y;

    this->xVel = -1;
    this->yVel = 0;
}