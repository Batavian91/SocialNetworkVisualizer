#pragma once
#include "AppState.h"

class GlobalState
{
private:
	const int WINDOW_WIDTH;
	const int WINDOW_HEIGHT;
	const float CANVAS_WIDTH;
	const float CANVAS_HEIGHT;
	AppState state;
protected:
	GlobalState();
	virtual ~GlobalState();
public:
	const int getWindowWidth() const;
	const int getWindowHeight() const;
	const int getCanvasWidth() const;
	const int getCanvasHeight() const;
	void setState(AppState);
	AppState getState() const;
	virtual void init() = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
};