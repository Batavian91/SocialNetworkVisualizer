#include "Submenu.h"
#include <graphics.h>
#include "Button.h"
#include "TextInput.h"

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
	style.fill_color[1] = 0.90f;
	style.fill_color[2] = 0.92f;
	graphics::setWindowBackground(style);

	username_input.draw(512.0f,125.0f, 400.0f, 68.0f);
	
}

void Submenu::update(float ms)
{
	username_input.update(ms);
}