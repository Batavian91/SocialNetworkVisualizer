#pragma once
//#include "Graph.h"
#include <graphics.h>

class Application
{
private:
	//Graph* graph;
public:
	Application();
	~Application();
	void init();
	void draw();
	void update(float);
	void createGraph();
	void deleteGraph();
};