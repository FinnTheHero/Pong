#pragma once
// Raylib
#include <raylib.h>

// Standard libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

// Custom headers
#include "ball.h"


class Paddle
{
public:
	float x, y;

	float width = 20, height = 120;

	float speed = 350;

	Paddle(float x, float y);

	void draw(Rectangle paddle);
	void speedUp();
};

class LeftPaddle : public Paddle {
public:
	LeftPaddle(float x, float y);

	Rectangle leftPaddleRec = { this->x, this->y, this->width, this->height };

	void collide(Ball& ball);
	void moveUp();
	void moveDown();
	void reset(float x, float y);
};

class RightPaddle : public Paddle {
public:
	RightPaddle(float x, float y);

	Rectangle rightPaddleRec = { this->x, this->y, this->width, this->height };

	void collide(Ball& ball);
	void moveUp();
	void moveDown();
	void reset(float x, float y);
};