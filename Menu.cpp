#include "Application.h"
#include "Menu.h"

#define BUTTON_X 512.0f
#define BUTTON_Y 125.0f
#define BUTTON_WIDTH 400.0f
#define BUTTON_HEIGHT 68.0f

Menu::Menu()
{
	buttons = new Button * [3];

	buttons[0] = new Button(BUTTON_X, BUTTON_Y,
		BUTTON_WIDTH, BUTTON_HEIGHT, "NEW PROFILE");
	buttons[1] = new Button(BUTTON_X, 2.0f * BUTTON_Y,
		BUTTON_WIDTH, BUTTON_HEIGHT, "SIMULATOR");
	buttons[2] = new Button(BUTTON_X, 3.0f * BUTTON_Y,
		BUTTON_WIDTH, BUTTON_HEIGHT, "EXIT");
}

Menu::~Menu()
{
	delete buttons[0];
	delete buttons[1];
	delete buttons[2];

	delete[] buttons;
}

void Menu::draw()
{
	buttons[0]->draw();
	buttons[1]->draw();
	buttons[2]->draw();
}

void Menu::update()
{
	Application* app = Application::getInstance();

	graphics::MouseState mouse;
	graphics::getMouseState(mouse);

	float mouse_pos_x =
		static_cast<float>(graphics::windowToCanvasX(mouse.cur_pos_x));
	float mouse_pos_y =
		static_cast<float>(graphics::windowToCanvasY(mouse.cur_pos_y));

	if (mouse.button_left_pressed
		&& mouse_pos_x > BUTTON_X - 0.5f * BUTTON_WIDTH
		&& mouse_pos_x < BUTTON_X + 0.5f * BUTTON_WIDTH
		&& mouse_pos_y > BUTTON_Y - 0.5f * BUTTON_HEIGHT
		&& mouse_pos_y < BUTTON_Y + 0.5f * BUTTON_HEIGHT)
	{
		graphics::playSound("assets\\hit1.wav",
			0.5f, false);

	}
	else if (mouse.button_left_pressed
		&& mouse_pos_x > BUTTON_X - 0.5f * BUTTON_WIDTH
		&& mouse_pos_x < BUTTON_X + 0.5f * BUTTON_WIDTH
		&& mouse_pos_y > 2.0f * BUTTON_Y - 0.5f * BUTTON_HEIGHT
		&& mouse_pos_y < 2.0f * BUTTON_Y + 0.5f * BUTTON_HEIGHT)
	{
		graphics::playSound("assets\\hit1.wav",
			1.0f, false);
		//app->setState(AppState::GRAPH);
	}
	else if (mouse.button_left_pressed
		&& mouse_pos_x > BUTTON_X - 0.5f * BUTTON_WIDTH
		&& mouse_pos_x < BUTTON_X + 0.5f * BUTTON_WIDTH
		&& mouse_pos_y > 3.0f * BUTTON_Y - 0.5f * BUTTON_HEIGHT
		&& mouse_pos_y < 3.0f * BUTTON_Y + 0.5f * BUTTON_HEIGHT)
	{
		app->setState(AppState::EXIT);
		graphics::stopMessageLoop();
	}
}