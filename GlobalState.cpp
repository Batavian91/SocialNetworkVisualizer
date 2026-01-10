#include "GlobalState.h"

GlobalState::GlobalState()
	: WINDOW_WIDTH(1200),
	WINDOW_HEIGHT(600),
	CANVAS_WIDTH(1024.0f),
	CANVAS_HEIGHT(512.0f),
	state(AppState::MAIN_MENU)
{
}

GlobalState::~GlobalState()
{
}

const int GlobalState::getWindowWidth() const
{
	return WINDOW_WIDTH;
}

const int GlobalState::getWindowHeight() const
{
	return WINDOW_HEIGHT;
}

const int GlobalState::getCanvasWidth() const
{
	return CANVAS_WIDTH;
}

const int GlobalState::getCanvasHeight() const
{
	return CANVAS_HEIGHT;
}

void GlobalState::setState(AppState newState)
{
	state = newState;
}

AppState GlobalState::getState() const
{
	return state;
}
