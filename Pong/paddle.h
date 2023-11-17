#pragma once
#include <iostream>
#include <raylib.h>
#include "ball.h"

class Paddle
{
public:
	// Paddle positions
	float x, y;
	
	// Paddle dimensions
	float width = 20, height = 100;
	
	// Paddle speed
	float speed = 350;

	// Constructor
	Paddle(float x, float y);
	
	// Paddle methods
	void draw(Rectangle paddle);
};

class LeftPaddle : public Paddle {
public:
	// Left padle constructor
	LeftPaddle(float x, float y);

	// Rectangle for collision
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
	
	// Rectangle for collision
	Rectangle rightPaddleRec = { this->x, this->y, this->width, this->height };

	// Right paddle methods
	void collide(Ball& ball);
	void moveUp();
	void moveDown();
	void reset(float x, float y);
};