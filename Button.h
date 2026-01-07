#pragma once
#include <graphics.h>
#include <string>

class Button
{
private:
	float m_x;
	float m_y;
	float m_width;
	float m_height;
	const std::string button_text;
	graphics::Brush background_style;
	graphics::Brush text_style;
public:
	Button(const std::string&);
	~Button();
	void draw(float, float, float, float);
};