#include "Submenu.h"
#include <graphics.h>

Submenu* Submenu::instance = nullptr;

Submenu::Submenu()
	:name("user")
{
}

Submenu::~Submenu()
{
}

Submenu* Submenu::getInstance()
{
	if (!instance)
		instance = new Submenu;

	return instance;
}

void Submenu::releaseInstance()
{
	if (instance)
		delete instance;
}

void Submenu::setName(std::string& newName)
{
	name = newName;
}

std::string& Submenu::getName()
{
	return name;
}

void Submenu::draw()
{
	graphics::Brush style;
	style.fill_color[0] = 0.85f;
	style.fill_color[1] = 0.10f;
	style.fill_color[2] = 0.92f;
	graphics::setWindowBackground(style);
	graphics::drawText(200.0f, 200.0f, 20.0f, "Type your name and press enter...", style);
	if (graphics::getKeyState(graphics::SCANCODE_ESCAPE))
	{
		graphics::drawText(200.0f, 200.0f, 20.0f, "Out...", style);
	}
}

void Submenu::update(float ms)
{
}