#include "Rectangle.h"

Rectangle::Rectangle(float w, float h)
	: width(w), height(h)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::setWidth(float newWidth)
{
	width = newWidth;
}

void Rectangle::setHeight(float newHeight)
{
	height = newHeight;
}

float Rectangle::getWidth() const
{
	return width;
}

float Rectangle::getHeight() const
{
	return height;
}