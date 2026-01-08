#pragma once
//#include "Graph.h"
#include <graphics.h>

class Application
{
private:
	//Graph* graph;
public:
	const int WINDOW_WIDTH;
	const int WINDOW_HEIGHT;
	const float CANVAS_WIDTH;
	const float CANVAS_HEIGHT;
	const float BUTTON_X;
	const float BUTTON_Y;
	const float BUTTON_WIDTH;
	const float BUTTON_HEIGHT;
	Application();
	~Application();
	void init();
	void draw();
	void update(float);
};