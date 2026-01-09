#include "Application.h"
#include "AppState.h"
#include "Submenu.h"
#include "Visualizer.h"
#include <graphics.h>

void draw()
{
	AppState* state = (AppState*)graphics::getUserData();

	switch (*state)
	{
	case AppState::APP_RUN:
	{
		Application* app = Application::getInstance();
		app->draw();
		break;
	}
	case AppState::SUBMENU:
	{
		//Submenu* menu = Submenu::getInstance();
		//menu->draw();
		//break;
	}
	case AppState::GRAPH:
	{
		//Visualizer* graph = Visualizer::getInstance();
		//graph->draw();
		//break;
	}
	default:
		break;
	}

}

// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{
	AppState* state = (AppState*)graphics::getUserData();

	switch (*state)
	{
	case AppState::APP_RUN:
	{
		Application* app = Application::getInstance();
		app->update(ms);
		break;
	}
	case AppState::SUBMENU:
	{
		//Submenu* menu = Submenu::getInstance();
		//menu->update(ms);
		//break;
	}
	case AppState::GRAPH:
	{
		//Visualizer* graph = Visualizer::getInstance();
		//graph->update(ms);
		//break;
	}
	default:
		break;
	}
}

int main()
{
	Application* app = Application::getInstance();
	Submenu* menu = Submenu::getInstance();
	//Visualizer* graph = Visualizer::getInstance();

	app->init();

	AppState state = AppState::APP_RUN;
	graphics::setUserData(&state);

	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);
	graphics::startMessageLoop();
	graphics::destroyWindow();

	app->releaseInstance();
	menu->releaseInstance();
	//graph->releaseInstance();

	return 0;
}