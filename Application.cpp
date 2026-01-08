#include "Application.h"
#include "Button.h"

Application::Application()
	: WINDOW_WIDTH(1200),
	WINDOW_HEIGHT(600),
	CANVAS_WIDTH(1024.0f),
	CANVAS_HEIGHT(512.0f),
	BUTTON_X(512.0f),
	BUTTON_Y(125.0f),
	BUTTON_WIDTH(400.0f),
	BUTTON_HEIGHT(68.0f)
{
}

Application::~Application()
{
	graphics::destroyWindow();
}

void Application::init()
{
	graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
		"Social Network Visualizer");
	graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
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
	Button button0("NEW PROFILE");
	button0.drawButton(BUTTON_X, BUTTON_Y,
		BUTTON_WIDTH, BUTTON_HEIGHT);

	Button button1("SIMULATOR");
	button1.drawButton(BUTTON_X, 2.0f * BUTTON_Y,
		BUTTON_WIDTH, BUTTON_HEIGHT);

	Button button2("EXIT");
	button2.drawButton(BUTTON_X, 3.0f * BUTTON_Y,
		BUTTON_WIDTH, BUTTON_HEIGHT);
}

void Application::update(float ms)
{
	graphics::MouseState mouse;
	graphics::getMouseState(mouse);
	
	float mouse_pos_x =
		(float)graphics::windowToCanvasX(mouse.cur_pos_x);
	float mouse_pos_y =
		(float)graphics::windowToCanvasY(mouse.cur_pos_y);

	if (mouse.button_left_pressed
		&& mouse_pos_x > BUTTON_X - 0.5f * BUTTON_WIDTH
		&& mouse_pos_x < BUTTON_X + 0.5f * BUTTON_WIDTH
		&& mouse_pos_y > BUTTON_Y - 0.5f * BUTTON_HEIGHT
		&& mouse_pos_y < BUTTON_Y + 0.5f * BUTTON_HEIGHT)
	{
		graphics::playSound("assets\\hit1.wav",
			1.0f, false);
	}
	else if (mouse.button_left_pressed
		&& mouse_pos_x > BUTTON_X - 0.5f * BUTTON_WIDTH
		&& mouse_pos_x < BUTTON_X + 0.5f * BUTTON_WIDTH
		&& mouse_pos_y > 2.0f * BUTTON_Y - 0.5f * BUTTON_HEIGHT
		&& mouse_pos_y < 2.0f * BUTTON_Y + 0.5f * BUTTON_HEIGHT)
	{
		graphics::playSound("assets\\hit1.wav",
			1.0f, false);
		graphics::playSound("assets\\hit1.wav",
			1.0f, false);
		graphics::playSound("assets\\hit1.wav",
			1.0f, false);
	}
	else if (mouse.button_left_pressed
		&& mouse_pos_x > BUTTON_X - 0.5f * BUTTON_WIDTH
		&& mouse_pos_x < BUTTON_X + 0.5f * BUTTON_WIDTH
		&& mouse_pos_y > 3.0f * BUTTON_Y - 0.5f * BUTTON_HEIGHT
		&& mouse_pos_y < 3.0f * BUTTON_Y + 0.5f * BUTTON_HEIGHT)
	{
		graphics::stopMessageLoop();
	}
}