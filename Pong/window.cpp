#include "window.h"

void createWindow()
{
	// Window starting dimensions
	int windowWidth = 800, windowHeight = 600;

	// Window name
	std::string windowName = "Pong";

	// Create the window
	InitWindow(windowWidth, windowHeight, windowName.c_str());

	// Adjust the window states
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetWindowState(FLAG_WINDOW_MAXIMIZED);
	SetWindowState(FLAG_WINDOW_ALWAYS_RUN);

	SetTargetFPS(60);
}