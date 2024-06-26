#pragma once
#include "Core.h"

using namespace std;

class Framework
{
public:
	Framework();
	Framework(unsigned int width, unsigned int height);
	virtual ~Framework();

	int Run(HINSTANCE hInstance, int nCmdShow);

	LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	inline unsigned int GetWindowWidth() { return _width; }
	inline unsigned int GetWindowHeight() { return _height; }
	inline HWND GetHWnd() {	return _hWnd; }

	// Initialise the application.  Called after the window and bitmap has been
	// created, but before the main loop starts
	//
	// Return false if the application cannot be initialised.
	virtual bool Initialise() {	return true; }

	// Perform any updates to the structures that will be used
	// to render the window (i.e. transformation matrices, etc).
	virtual void Update() {}

	// Render the contents of the window. 
	virtual void Render() {};

	// Perform any application shutdown or cleanup that is needed
	virtual void Shutdown() {}

	// Handlers for Windows messages. If you need more, add them
	// here and call them from MsgProc. The only one we need to handle is WM_SIZE
	virtual void OnResize(WPARAM wParam) {}
	virtual void OnMouseClick(int x, int y, bool isDown) {}
	virtual void OnMouseMoveRaw(int x, int y) {}
	virtual void OnMouseWheel(int x, int y, bool isDown) {}
	virtual void OnKey(WPARAM wParam, bool isDown) {}

private:
	HINSTANCE		_hInstance;
	HWND			_hWnd;
	unsigned int	_width;
	unsigned int	_height;

	// Used in timing loop
	double			_timeSpan;

	bool InitialiseMainWindow(int nCmdShow);
	int MainLoop();
};

