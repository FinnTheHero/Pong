#pragma once
#include "raylib.h"
#include <cmath>

class Ball
{
public:
	// Ball positions
	float x = GetScreenWidth() / 2, y = GetScreenHeight() / 2;

	// Ball dimensions
	float width = 20, height = 20;

	// Ball directions
	float xVel = -1, yVel = 0;

	// Ball speed
	float speed = 400;

	// Ball rectangle
	Rectangle ballRec = { this->x, this->y, this->width, this->height };

	// Ball Methods
	void draw();
	void move();
	void collide();
	void reset(float x, float y);
};