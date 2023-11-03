#pragma once
#include "raylib.h"
#include <cmath>

class Ball
{
public:
	// Ball positions
	int x = GetScreenWidth() / 2, y = GetScreenHeight() / 2;

	// Ball Dimensions
	const int width = 20, height = 20;

	// Ball directions
	float xVel = 0.0, yVel = 1.0;

	// Ball speed
	double speed = 200;

	// Methods
	void draw();
	void move();
	void collide();
};