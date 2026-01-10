#include "VisualAsset.h"

VisualAsset::VisualAsset(float x, float y)
	: pos_x(x), pos_y(y)
{
}

VisualAsset::~VisualAsset()
{
}

void VisualAsset::setX(float newX)
{
	pos_x = newX;
}

void VisualAsset::setY(float newY)
{
	pos_y = newY;
}

float VisualAsset::getX() const
{
	return pos_x;
}

float VisualAsset::getY() const
{
	return pos_y;
}