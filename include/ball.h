#pragma once
// Raylib
#include <raylib.h>

// Standard libraries
#include <cmath>


class Ball
{
public:
	float x = 0, y = 0;

	float width = 20, height = 20;

	float xVel, yVel;

	float speed = 400;

	Ball(float x, float y, float xVel, float yVel);
	
	Rectangle ballRec = { this->x, this->y, this->width, this->height };

	void draw();
	void move();
	void collide();
	void reset(float x, float y, float xVel, float yVel);
	void speedUp();
};