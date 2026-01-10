#include "Connection.h"

Connection::Connection()
{
	style.outline_color[0] = 1.0f;
	style.outline_color[1] = 0.3f;
	style.outline_color[2] = 0.1f;
	style.outline_opacity = 0.5f;
	style.outline_width = 1.0f;
}

Connection::~Connection()
{
}

void Connection::draw()
{
	graphics::drawLine(
		getStartingNode()->getX(),
		getStartingNode()->getY(),
		getEndingNode()->getX(),
		getEndingNode()->getY(),
		style);
}