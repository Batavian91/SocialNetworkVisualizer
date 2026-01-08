#include "Application.h"
#include "AppState.h"
#include "Graph.h"
#include "Button.h"
#include <graphics.h>

void draw()
{
	AppState* state = (AppState*)graphics::getUserData();

	switch (*state)
	{
	case AppState::APP_RUN:
	{
		Application* app = Application::getInstance();
		app->draw();
	}
	default:
		break;
	}

}

// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{
	AppState* state = (AppState*)graphics::getUserData();

	switch (*state)
	{
	case AppState::APP_RUN:
	{
		Application* app = Application::getInstance();
		app->update(1.0f);
	}
	default:
		break;
	}
}

int main()
{

	// THIS WILL BE MOVED IN THE GRAPH
	// THE GRAPH WILL BE CHANGED
	/*Graph* g = new Graph;
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
	delete g;*/

	Application* app = Application::getInstance();
	app->init();

	AppState state = AppState::APP_RUN;
	graphics::setUserData(&state);

	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);
	graphics::startMessageLoop();
	graphics::destroyWindow();

	app->releaseInstance();

	return 0;
}