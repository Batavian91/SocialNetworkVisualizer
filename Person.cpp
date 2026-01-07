#include "Person.h"
#include <graphics.h>

Person::Person()
	: m_x(0.0f), m_y(0.0f),
	m_width(0.0f), m_height(0.0f)
{
}

Person::~Person()
{
}

float Person::getX() const
{
	return m_x;
}

float Person::getY() const
{
	return m_y;
}

void Person::draw(float x, float y, float w, float h)
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;

	graphics::Brush brush;

	brush.texture = "assets\\avatar_01_128.png";
	/*
	brush.outline_opacity = 0.0f;
	brush.fill_color[0] = 0.5f;
	brush.fill_color[1] = 0.0f;
	brush.fill_color[2] = 0.0f;
	*/
	graphics::drawRect(x, y, w, h, brush);
	graphics::drawText(x - w / 2, y + h, 10.0f,
		"Person " + std::to_string(getUID()), brush);
	graphics::resetPose();
}