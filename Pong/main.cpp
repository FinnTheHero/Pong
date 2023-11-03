#include <iostream>
#include <raylib.h>

int main(void) {
	
	// Window minimum dimensions & starting point
	const int windowMinWidth = 800, windowMinHeight = 600;
	
	// Window Name
	std::string windowName = "Pong";
	
	// Create Window
	InitWindow(windowMinWidth,windowMinHeight,windowName.c_str());

	// Make window resizable using flags
	SetWindowState(FLAG_WINDOW_RESIZABLE);

	SetTargetFPS(60);

	// Main loop
	while(!WindowShouldClose())
	{
		BeginDrawing();
		
		// Set background to white
		ClearBackground(RAYWHITE);
		
		// Draw FPS in top left corner
		DrawFPS(10, 10);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}