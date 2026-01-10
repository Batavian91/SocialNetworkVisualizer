#include "Application.h"
#include "Menu.h"
#include <graphics.h>

Application* Application::app_instance = nullptr;

Application::Application()
{
	menu = new Menu;
}

Application::~Application()
{
	delete menu;
}

Application* Application::getInstance()
{
	if (!app_instance)
		app_instance = new Application;

	return app_instance;
}

void Application::deleteInstance()
{
	if (app_instance)
		delete app_instance;
}

void Application::init()
{
	graphics::createWindow(getWindowWidth(),
		getWindowHeight(), "Social Network Visualizer");
	graphics::setCanvasSize(getCanvasWidth(),
		getCanvasHeight());
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	graphics::setFont("assets\\orange juice 2.0.ttf");

	graphics::Brush style;
	style.fill_color[0] = 0.85f;
	style.fill_color[1] = 0.90f;
	style.fill_color[2] = 0.92f;
	graphics::setWindowBackground(style);
}

void Application::draw()
{
	if (getState() == AppState::MAIN_MENU)
	{
		menu->draw();
	}
}

void Application::update()
{
	if (getState() == AppState::MAIN_MENU)
	{
		menu->update();
	}

}