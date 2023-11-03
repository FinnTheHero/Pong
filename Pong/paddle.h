#pragma once
#include <iostream>
#include <raylib.h>
#include "ball.h"

class Paddle
{
public:
	// Paddle positions
	int x = 20, y = GetScreenHeight() / 2;
	
	// Paddle dimensions
	const int width = 20, height = 80;
	
	// Paddle speed
	int speed = 200;
	
	// Paddle methods
	void draw();
	void move();
	void collide(Ball& ball);
};