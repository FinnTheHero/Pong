#pragma once
// Raylib
#include <raylib.h>

// Standard libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Custom headers
#include "ball.h"


class Paddle
{
public:
	// Paddle positions
	float x, y;
	
	// Paddle dimensions
	float width = 20, height = 120;
	
	// Paddle speed
	float speed = 350;

	// Constructor
	Paddle(float x, float y);
	
	// Paddle methods
	void draw(Rectangle paddle);
	void speedUp();
};

class LeftPaddle : public Paddle {
public:
	// Left padle constructor
	LeftPaddle(float x, float y);

	// Rectangle for left paddle
	Rectangle leftPaddleRec = { this->x, this->y, this->width, this->height };

	// Left paddle methods
	void collide(Ball& ball);
	void moveUp();
	void moveDown();
	void reset(float x, float y);
};

class RightPaddle : public Paddle {
public:
	// Right paddle constructor
	RightPaddle(float x, float y);
	
	// Rectangle for right paddle
	Rectangle rightPaddleRec = { this->x, this->y, this->width, this->height };

	// Right paddle methods
	void collide(Ball& ball);
	void moveUp();
	void moveDown();
	void reset(float x, float y);
};