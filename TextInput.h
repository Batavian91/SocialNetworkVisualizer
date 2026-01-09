#pragma once
#include <graphics.h>
#include <string>

class TextInput
{
private:
	graphics::Brush background_style;
	graphics::Brush text_style;
	std::string state;
	graphics::scancode_t getPressedKey();
public:
	TextInput();
	~TextInput();
	std::string getText();
	float getTextX(float);
	float getTextY(float, float);
	void draw(float, float, float, float);
	void update(float);
};
