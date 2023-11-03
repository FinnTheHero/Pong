#include "window.h"

void createWindow()
{
	// Window minimum dimensions & starting point
	const int windowMinWidth = 800, windowMinHeight = 600;

	// Window Name
	std::string windowName = "Pong";

	// Create Window
	InitWindow(windowMinWidth, windowMinHeight, windowName.c_str());

	// Make window resizable using flags
	SetWindowState(FLAG_WINDOW_RESIZABLE);

	SetTargetFPS(120);
}