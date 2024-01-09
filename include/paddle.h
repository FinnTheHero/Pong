#pragma once
// Raylib
#include <raylib.h>

// Standard libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

// Custom headers
#include "ball.h"


class Paddle
{
public:
	float x = 0, y = 0;

	float width = 20, height = 120;

	float speed = 350;

	Paddle(float x, float y);

	Rectangle paddleRec = { this->x, this->y, this->width, this->height };

	void draw();
	void speedUp();
	void collide(Ball& ball);
	void reset(float x, float y);
	void moveUp(KeyboardKey key);
	void moveDown(KeyboardKey key);
};