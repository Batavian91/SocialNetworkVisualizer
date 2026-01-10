#include "Person.h"

Person::Person(float x, float y, float w, float h, 
	const std::string& newName, const std::string& path)
	: Node(x, y),
	Rectangle(w, h),
	name(newName)
{
	style.fill_color[0] = 0.5f;
	style.fill_color[1] = 0.0f;
	style.fill_color[2] = 0.0f;
	style.outline_opacity = 0.0f;
	style.texture = path;
}

Person::~Person()
{
}

const std::string& Person::getName() const
{
	return name;
}

void Person::draw()
{
	float x = getX();
	float y = getY();
	float w = getWidth();
	float h = getHeight();

	graphics::drawRect(x, y, w, h, style);
	graphics::drawText(x - w / 2, y + h,
		10.0f, name, style);
}