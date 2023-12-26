#include "window.h"

void createWindow()
{
	// Window starting dimensions
	float windowWidth = 0, windowHeight = 0;

	// Window name
	std::string windowName = "Pong";

	// Create the window
	InitWindow(windowWidth, windowHeight, windowName.c_str());

	// Adjust the window states
	SetWindowState(FLAG_VSYNC_HINT);
	SetWindowState(FLAG_FULLSCREEN_MODE);

	// Manually cap the framerate to 60
	SetTargetFPS(144);

	// Hide the cursor
	HideCursor();

	SetExitKey(KEY_DELETE);
}