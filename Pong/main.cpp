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

	// Create paddle object
	Paddle paddle;

	// Main loop
	while(!WindowShouldClose())
	{
		BeginDrawing();
		
		// Set background to white
		ClearBackground(BLACK);
		
		// Paddle methods
		paddle.draw();
		paddle.move();
		paddle.collide(ball);

		// Ball methods
		ball.draw();
		ball.move();
		ball.collide();

		// Draw FPS in top left corner
		DrawFPS(10, 10);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}