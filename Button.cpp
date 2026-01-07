#include "Button.h"

Button::Button(const std::string& text)
	: m_x(0.0f), m_y(0.0f),
	m_width(0.0f), m_height(0.0f),
	button_text(text)
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
	text_style.fill_color[0] = 0.0f;
	text_style.fill_color[1] = 0.0f;
	text_style.fill_color[2] = 0.0f;
}

Button::~Button()
{
}

void Button::draw(float x, float y, float w, float h)
{
	graphics::drawRect(x, y, w, h, background_style);
	graphics::drawText(x - 1.5f * h, y + 0.4f * h, h,
		button_text, text_style);
	//button.draw(500.f, 100.0f, 200.0f, 50.0f);
}