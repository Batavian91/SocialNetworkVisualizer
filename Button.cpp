#include "Button.h"

Button::Button(const std::string& text)
	: BUTTON_TEXT(text)
{
	background_style.fill_color[0] = 0.9f;
	background_style.fill_color[1] = 0.7f;
	background_style.fill_color[2] = 0.2f;
	background_style.fill_secondary_color[0] = 0.3f;
	background_style.fill_secondary_color[1] = 0.2f;
	background_style.fill_secondary_color[2] = 0.3f;
	background_style.fill_opacity = 1.0f;
	background_style.fill_secondary_opacity = 1.0f;
	background_style.outline_color[0] = 0.5f;
	background_style.outline_color[1] = 0.5f;
	background_style.outline_color[2] = 0.5f;
	background_style.outline_width = 1.0f;
	background_style.texture = "";
	background_style.gradient = true;
	background_style.gradient_dir_u = 0.4f;
	background_style.gradient_dir_v = 0.5f;
	text_style.fill_color[0] = 1.0f;
	text_style.fill_color[1] = 1.0f;
	text_style.fill_color[2] = 1.0f;
}

Button::~Button()
{
}

float Button::getTextX(float x) const
{
	float letter;
	if (BUTTON_TEXT == "SIMULATOR")
		letter = 35.0f;
	else 
		letter = 31.0f;
	float width = letter * BUTTON_TEXT.length();
	return x - width / 2.0f;
}

float Button::getTextY(float y, float h) const
{
	return y + 0.3 * h;
}

void Button::drawButton(float x, float y, float w, float h)
{
	graphics::drawRect(x, y, w, h, background_style);
	graphics::drawText(getTextX(x), getTextY(y, h),
		0.8f * h, BUTTON_TEXT, text_style);
}