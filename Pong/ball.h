#pragma once
#include "raylib.h"
#include <cmath>

class Ball
{
public:
	// Ball positions
	int x = GetScreenWidth() / 2, y = GetScreenHeight() / 2;

	// Ball dimensions
	const int width = 20, height = 20;

	// Ball directions
	float xVel = -1.0, yVel = 0.0;

	// Ball speed
	int speed = 200;

	// Ball Methods
	void draw();
	void move();
	void collide();
};