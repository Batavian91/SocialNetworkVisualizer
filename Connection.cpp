#include "Connection.h"
#include <graphics.h>

Connection::Connection()
{
}

Connection::~Connection()
{
}

void Connection::draw()
{
	graphics::Brush brush;

	brush.outline_opacity = 0.5f;
	brush.outline_width = 100.0f;
	brush.outline_color[0] = 1.0f;
	brush.outline_color[1] = 0.0f;
	brush.outline_color[2] = 0.0f;

	graphics::drawLine(
		getStartingNode()->getX(),
		getStartingNode()->getY(),
		getEndingNode()->getX(),
		getEndingNode()->getY(),
		brush);
}