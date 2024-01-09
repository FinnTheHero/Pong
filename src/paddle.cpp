#include "paddle.h"

Paddle::Paddle(float x, float y)
{
	this->x = x;
	this->y = y;
}

LeftPaddle::LeftPaddle(float x, float y) : Paddle(x, y) {
	paddleRec = { this->x, this->y, this->width, this->height };
}

RightPaddle::RightPaddle(float x, float y) : Paddle(x, y) {
	paddleRec = { this->x, this->y, this->width, this->height };
}

void Paddle::draw()
{
	DrawRectangleRec(paddleRec, GREEN);
}

void Paddle::speedUp()
{
	if (this->speed < 750)
	{
		this->speed += 1;
	}
}

void Paddle::collide(Ball& ball)
{
	if (CheckCollisionRecs(paddleRec, ball.ballRec))
	{

		ball.xVel = -ball.xVel;
		ball.speedUp();		

		// Randomize ball's direction
		std::srand(std::time(0));
		if (ball.yVel < 0.0f) {
			std::mt19937 rng(std::random_device{}());
			std::uniform_real_distribution<double> dist(-0.8, -0.2);
			ball.yVel = dist(rng);
		}
		else {
			std::mt19937 rng(std::random_device{}());
			std::uniform_real_distribution<double> dist(0.2, 0.8);
			ball.yVel = dist(rng);
		}
	}
}

void Paddle::reset(float x, float y)
{
	if (this->speed - (this->speed / 2) > 350)
	{
		this->speed = this->speed / 2;
	}

	paddleRec.x = x;
	paddleRec.y = y;
}

void Paddle::moveUp(KeyboardKey key)
{
	if (IsKeyDown(key) && paddleRec.y > 0)
	{
		paddleRec.y -= GetFrameTime() * this->speed;
		speedUp();
	}
}

void Paddle::moveDown(KeyboardKey key)
{
	if (IsKeyDown(key) && paddleRec.y + paddleRec.height < GetScreenHeight())
	{
		paddleRec.y += GetFrameTime() * this->speed;
		speedUp();
	}
}