// Standard libraries
#include <iostream>

// Include Raylib
#include <raylib.h>

// Game files
#include "window.h"
#include "ball.h"

int main(void) {
	
	createWindow();

	// Create ball object
	Ball ball;

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

		// Draw FPS in top left corner
		DrawFPS(10, 10);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}