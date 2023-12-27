#include "window.h"

void createWindow()
{
	// Monitor ID
	int monitor = 0;

	// Create the window
	InitWindow(GetMonitorWidth(monitor), GetMonitorHeight(monitor), "Pong");

	// Pick monitor
	SetWindowMonitor(monitor);

	// Adjust the window states
	SetWindowState(FLAG_VSYNC_HINT);
	SetWindowState(FLAG_FULLSCREEN_MODE);

	// Make FPS same as monitor refresh rate
	int monitorRefreshRate = GetMonitorRefreshRate(monitor);
	SetTargetFPS(monitorRefreshRate);

	HideCursor();

	SetExitKey(KEY_DELETE);
}