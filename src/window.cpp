#include "../include/window.h"

void createWindow()
{
	// Adjust the window states
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_FULLSCREEN_MODE);

	// Create the window
	InitWindow(0, 0, "Pong");

	HideCursor();

	SetExitKey(KEY_DELETE);
}