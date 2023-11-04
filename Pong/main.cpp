// Standard libraries
#include <iostream>

// Include Raylib
#include <raylib.h>

// Game files
#include "window.h"
#include "ball.h"
#include "paddle.h"

int main(void) {
	
	createWindow();

	// Create ball object
	Ball ball;

	// Create left paddle object
	LeftPaddle leftPaddle(30,GetScreenHeight() / 2);

	// Create right paddle object
	RightPaddle RightPaddle(GetScreenWidth() - 50, GetScreenHeight() / 2);

	// Main loop
	while(!WindowShouldClose())
	{
		BeginDrawing();
		
		// Set background to white
		ClearBackground(BLACK);
		
		// Ball methods
		ball.draw();
		ball.move();
		ball.collide();

		// Left paddle methods
		leftPaddle.collide(ball);
		leftPaddle.draw();
		leftPaddle.moveUp();
		leftPaddle.moveDown();

		// Right paddle methods
		RightPaddle.collide(ball);
		RightPaddle.draw();
		RightPaddle.moveUp();
		RightPaddle.moveDown();

		// Draw FPS in top left corner
		DrawFPS(10, 10);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}