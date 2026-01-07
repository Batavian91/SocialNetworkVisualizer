#include "Application.h"

Application::Application()
{
}

Application::~Application()
{
	graphics::destroyWindow();
}

void Application::init()
{
	graphics::createWindow(1200, 600,
		"Social Network Visualizer");
	graphics::setCanvasSize(1024.0f, 512.0f);
	graphics::setCanvasScaleMode(graphics::
		CANVAS_SCALE_FIT);


	graphics::setFont("assets\\orange juice 2.0.ttf");

	graphics::Brush style;
	style.fill_color[0] = 0.85f;
	style.fill_color[1] = 0.90f;
	style.fill_color[2] = 0.92f;
	graphics::setWindowBackground(style);
}

void Application::draw()
{
}

void Application::update(float ms)
{
	graphics::MouseState mouse;
	graphics::getMouseState(mouse);
	if (mouse.button_left_released)
	{
		graphics::playSound("assets\\hit1.wav", 
			1.0f, false);
	}
}

void Application::createGraph()
{
}

void Application::deleteGraph()
{
}