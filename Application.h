#pragma once

class Application
{
private:
	static Application* app_instance;
	Application();
	~Application();
public:
	const int WINDOW_WIDTH;
	const int WINDOW_HEIGHT;
	const float CANVAS_WIDTH;
	const float CANVAS_HEIGHT;
	const float BUTTON_X;
	const float BUTTON_Y;
	const float BUTTON_WIDTH;
	const float BUTTON_HEIGHT;
	static Application* getInstance();
	static void releaseInstance();
	void init();
	void draw();
	void update(float);
};