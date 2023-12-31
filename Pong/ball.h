#pragma once
// Raylib
#include <raylib.h>

// Standard libraries
#include <cmath>


class Ball
{
public:
	float x = GetScreenWidth() / 2, y = GetScreenHeight() / 2;

	float width = 20, height = 20;

	float xVel = -1, yVel = 0;

	float speed = 400;

	Rectangle ballRec = { this->x, this->y, this->width, this->height };

	void draw();
	void move();
	void collide();
	void reset(float x, float y);
	void speedUp();
};