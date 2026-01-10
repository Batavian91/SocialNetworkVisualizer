#pragma once
#include <graphics.h>

class VisualAsset
{
private:
	float pos_x;
	float pos_y;
public:
	graphics::Brush style;
	VisualAsset(float, float);
	~VisualAsset();
	void setX(float);
	void setY(float);
	float getX() const;
	float getY() const;
	virtual void draw() = 0;
};