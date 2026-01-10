#include "Button.h"

Button::Button()
	:VisualAsset(0.0f, 0.0f), 
	Rectangle(0.0f, 0.0f),
	BUTTON_TEXT("BUTTON")
{
}

Button::Button(float x, float y, float w,
	float h, const std::string& text)
	: VisualAsset(x, y), Rectangle(w, h),
	BUTTON_TEXT(text)
{
	style.fill_color[0] = 0.9f;
	style.fill_color[1] = 0.7f;
	style.fill_color[2] = 0.2f;
	style.fill_secondary_color[0] = 0.3f;
	style.fill_secondary_color[1] = 0.2f;
	style.fill_secondary_color[2] = 0.3f;
	style.fill_opacity = 1.0f;
	style.fill_secondary_opacity = 1.0f;
	style.outline_color[0] = 0.5f;
	style.outline_color[1] = 0.5f;
	style.outline_color[2] = 0.5f;
	style.outline_opacity = 0.0f;
	style.outline_width = 1.0f;
	style.texture = "";
	style.gradient = true;
	style.gradient_dir_u = 0.4f;
	style.gradient_dir_v = 0.5f;
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

void Button::draw()
{
	float x = getX();
	float y = getY();
	float w = getWidth();
	float h = getHeight();

	graphics::drawRect(x, y, w, h, style);
	graphics::drawText(getTextX(x), getTextY(y, h),
		0.8f * h, BUTTON_TEXT, text_style);
}