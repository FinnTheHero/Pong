#pragma once
#include <iostream>
#include <raylib.h>
#include "ball.h"

class Paddle
{
public:
	// Paddle positions
	int x, y;
	
	// Paddle dimensions
	const int width = 25, height = 100;
	
	// Paddle speed
	int speed = 350;

	// Constructor
	Paddle(int x, int y);
	
	// Paddle methods
	void draw();
};

class LeftPaddle : public Paddle {
public:
	// Left padle constructor
	LeftPaddle(int x, int y);

	// Left paddle methods
	void collide(Ball& ball);
	void moveUp();
	void moveDown();
};

class RightPaddle : public Paddle {
public:

	// Right paddle constructor
	RightPaddle(int x, int y);
	
	// Right paddle methods
	void collide(Ball& ball);
	void moveUp();
	void moveDown();
};