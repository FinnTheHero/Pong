#include "ball.h"

void Ball::draw()
{
    DrawRectangleRec(ballRec, GREEN);
}

void Ball::move()
{
    ballRec.x += this->xVel * GetFrameTime() * this->speed;
    ballRec.y += this->yVel * GetFrameTime() * this->speed;
}

void Ball::collide()
{
    // Collide bottom
    if (ballRec.y + ballRec.height >= GetScreenHeight())
    {
        if (this->yVel > 0)
        {
            this->yVel = -this->yVel;
        }
    }

    // Colide top
    if (ballRec.y <= 0)
    {
        if (this->yVel < 0)
        {
            this->yVel = -this->yVel;
        }
    }
}

void Ball::reset(float x, float y)
{
    ballRec.x = x;
    ballRec.y = y;

    this->xVel = -1;
    this->yVel = 0;

    if (this->speed - ((this->speed / 3) * 2) > 350)
    {
        this->speed = (this->speed / 3) * 2;
    }
}

void Ball::speedUp()
{
    if (this->speed < 1100)
    {
        this->speed += 10;
    }
}