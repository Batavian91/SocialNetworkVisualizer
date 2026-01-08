#include "Application.h"
#include "Graph.h"
#include "Button.h"
#include <graphics.h>

// The custom callback function that the library calls 
// to check for and set the current application state.
//void update(float ms)
//{
//	graphics::MouseState mouse;
//	graphics::getMouseState(mouse);
//	if (mouse.button_left_released)
//	{
//		graphics::playSound("assets\\hit1.wav", 1.0f, false);
//	}
//}

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
	
	graphics::setDrawFunction([app] {app->draw(); });
	graphics::setUpdateFunction([app](float) {app->update(1.0f); });
	graphics::startMessageLoop();

	delete g;
	delete app;

	return 0;
}