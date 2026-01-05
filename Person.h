#pragma once
#include "Node.h"

class Person : public Node
{
private:
	// x-axis coordinate
	float m_x;

	// y-axis coordinate
	float m_y;

	// width value
	float m_width;

	// height value
	float m_height;

public:
	// Person constructor
	Person();

	// Person destructor
	~Person();

	// getters for each Node's coordinates and sizes
	float getX() const;
	float getY() const;

	// implements base's class function 
	// draw() - draws a Person
	void draw(float, float, float, float);
};