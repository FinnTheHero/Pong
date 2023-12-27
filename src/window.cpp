#include "../include/window.h"

void createWindow()
{
	int monitor = 0;

	// Create the window
	InitWindow(GetMonitorWidth(monitor), GetMonitorHeight(monitor), "Pong");

	// Set primary monitor to run on
	SetWindowMonitor(monitor);

	// Adjust the window states
	SetWindowState(FLAG_VSYNC_HINT);
	SetWindowState(FLAG_FULLSCREEN_MODE);
	
	// Manually cap the framerate to 144
	SetTargetFPS(144);

	// Hide the cursor
	HideCursor();

	// std::cout << GetMonitorCount() << std::endl;
	// std::cout << GetCurrentMonitor() << std::endl;

	// std::cout << GetMonitorName(GetCurrentMonitor()) << std::endl;
	// std::cout << GetMonitorWidth(GetCurrentMonitor()) << std::endl;
	// std::cout << GetMonitorHeight(GetCurrentMonitor()) << std::endl;
	// std::cout << GetRenderWidth() << std::endl;
	// std::cout << GetRenderHeight() << std::endl;
	// std::cout << GetScreenWidth() << std::endl;
	// std::cout << GetScreenHeight() << std::endl;

	SetExitKey(KEY_DELETE);
}