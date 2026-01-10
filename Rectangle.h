#pragma once

class Rectangle
{
private:
	float width;
	float height;
public:
	Rectangle(float, float);
	virtual ~Rectangle();
	void setWidth(float);
	void setHeight(float);
	float getWidth() const;
	float getHeight() const;
};