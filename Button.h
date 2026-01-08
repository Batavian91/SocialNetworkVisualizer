#pragma once
#include <graphics.h>
#include <string>

class Button
{
private:
	const std::string BUTTON_TEXT;
	graphics::Brush background_style;
	graphics::Brush text_style;
public:
	Button(const std::string&);
	~Button();
	float getTextX(float) const;
	float getTextY(float, float) const;
	void drawButton(float, float, float, float);
};