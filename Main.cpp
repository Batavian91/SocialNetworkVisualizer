#include "Application.h"
#include "Graph.h"
#include "Button.h"
#include "Menu.h"
#include <graphics.h>
#include <functional>

void init()
{
	graphics::createWindow(1200, 600,
		"Social Network Visualizer");
	graphics::setCanvasSize(1024.0f, 512.0f);
	graphics::setCanvasScaleMode(graphics::
		CANVAS_SCALE_FIT);
}

// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{
	graphics::MouseState mouse;
	graphics::getMouseState(mouse);
	if (mouse.button_left_released)
	{
		graphics::playSound("assets\\hit1.wav", 1.0f, false);
	}
}

int main()
{
	Graph* g = new Graph;
	unsigned int id = g->addNode();
	unsigned int id2 = g->addNode();
	unsigned int id3 = g->addNode();
	unsigned int id4 = g->addNode();
	unsigned int id5 = g->addNode();
	unsigned int id6 = g->addNode();
	g->addEdge(g->getNode(id), g->getNode(id2));
	g->addEdge(g->getNode(id3), g->getNode(id6));
	g->addEdge(g->getNode(id3), g->getNode(id5));
	g->addEdge(g->getNode(id4), g->getNode(id5));
	g->addEdge(g->getNode(id6), g->getNode(id2));

	Application* app = new Application;
	app->init();

	//init();

	//Menu* m = new Menu;

	//m->init();
	
	graphics::setDrawFunction([g] {g->draw(); });
	//graphics::setDrawFunction([m] { m->draw(); });
	graphics::setUpdateFunction(update);
	graphics::startMessageLoop();
	//graphics::destroyWindow();

	//delete m;
	delete g;
	delete app;

	return 0;
}