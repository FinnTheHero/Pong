#include "../include/window.h"

void createWindow()
{
	// Window starting dimensions
	float windowWidth = 800, windowHeight = 600;

	// Window name
	std::string windowName = "Pong";

	// Create the window
	InitWindow(windowWidth, windowHeight, windowName.c_str());

	// Adjust the window states
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetWindowState(FLAG_WINDOW_MAXIMIZED);
	
	// Make window un-resizable after adjusting
	ClearWindowState(FLAG_WINDOW_RESIZABLE);

	// Make game always run even on minimized
	SetWindowState(FLAG_WINDOW_ALWAYS_RUN);

	SetTargetFPS(60);

	SetExitKey(KEY_NULL);
}