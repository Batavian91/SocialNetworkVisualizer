#include "Submenu.h"
#include <graphics.h>
#include <iostream>
#include "Button.h"
#include "TextInput.h"

Submenu* Submenu::instance = nullptr;

Submenu::Submenu()
	:name("user"), input_button(Button("PRINT TEXT"))
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

	username_input.draw(512.0f, 125.0f, 800.0f, 68.0f);
	input_button.drawButton(512.0f, 225.0f, 350.0f, 68.0f);

}

void Submenu::update(float ms)
{
	username_input.update(ms);

	graphics::MouseState mouse;
	graphics::getMouseState(mouse);

	float mouse_pos_x =
		(float)graphics::windowToCanvasX(mouse.cur_pos_x);
	float mouse_pos_y =
		(float)graphics::windowToCanvasY(mouse.cur_pos_y);

	if (mouse.button_left_pressed
		&& mouse_pos_x > 512.0f - 0.5f * 350.0f
		&& mouse_pos_x < 512.0f + 0.5f * 350.0f
		&& mouse_pos_y > 225.0f - 0.5f * 68.0f
		&& mouse_pos_y < 225.0f + 0.5f * 68.0f)
	{
		std::cout<< "Input text: " << username_input.getText() << std::endl;
	}
}