#include "Application.h"
#include <graphics.h>

// The window content drawing function.
void draw()
{
	Application* app = Application::getInstance();
	app->draw();
}

// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{
	Application* app = Application::getInstance();
	app->update();
}

int main()
{
	Application* app = Application::getInstance();
	app->init();

	graphics::setUserData(app);
	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);
	graphics::startMessageLoop();
	graphics::destroyWindow();

	app->deleteInstance();

	return 0;
}