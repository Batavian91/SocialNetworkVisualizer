#include "TextInput.h"

graphics::scancode_t TextInput::getPressedKey()
{
	{
		for (int i = 1; i < graphics::scancode_t::NUM_SCANCODES; i++)
		{
			graphics::scancode_t key = static_cast<graphics::scancode_t>(i);
			if (getKeyState(key))
			{
				return key;
			}
		}
		
		return graphics::SCANCODE_UNKNOWN;
	}
}

TextInput::TextInput()
{ 
	background_style.fill_color[0] = 1.0f;
	background_style.fill_color[1] = 1.0f;
	background_style.fill_color[2] = 1.0f;
	background_style.fill_opacity = 1.0f;
	background_style.outline_color[0] = 0.5f;
	background_style.outline_color[1] = 0.5f;
	background_style.outline_color[2] = 0.5f;
	background_style.outline_width = 1.0f;
	background_style.texture = "";
	text_style.fill_color[0] = 0.0f;
	text_style.fill_color[1] = 0.0f;
	text_style.fill_color[2] = 0.0f;
}

TextInput::~TextInput()
{
}

std::string TextInput::getText()
{
	return state;
}

float TextInput::getTextX(float x) 
{
	float letter= 31.0f;
	float width = letter * state.length();
	return x - width / 2.0f;
}

float TextInput::getTextY(float y, float h) 
{
	return y + 0.3 * h;
}

void TextInput::draw(float x, float y, float width, float height)
{
	graphics::drawRect(x, y, width, height, background_style);
	graphics::drawText(getTextX(x), getTextY(y, height),
		0.8f * height, state, text_style);
}

void TextInput::update(float ms) 
{
}