#include "graphics.h"
#include<unordered_map>

static std::unordered_map<graphics::scancode_t, bool> previousKeyStates;

graphics::scancode_t getKeyPressed()
{
	for (int i = 1; i < graphics::NUM_SCANCODES; i++)
	{
		graphics::scancode_t key = static_cast<graphics::scancode_t>(i);
		if (graphics::getKeyState(key))
		{
			return key;
		}
	}

	return graphics::SCANCODE_UNKNOWN;
}

char scancodeToChar(graphics::scancode_t key, bool shift)
{
	if (key >= graphics::SCANCODE_A && key <= graphics::SCANCODE_Z)
	{
		char base = 'a' + (key - graphics::SCANCODE_A);
		return shift ? (base - 32) : base;
	}

	if (!shift)
	{
		switch (key)
		{
		case graphics::SCANCODE_1: return '1';
		case graphics::SCANCODE_2: return '2';
		case graphics::SCANCODE_3: return '3';
		case graphics::SCANCODE_4: return '4';
		case graphics::SCANCODE_5: return '5';
		case graphics::SCANCODE_6: return '6';
		case graphics::SCANCODE_7: return '7';
		case graphics::SCANCODE_8: return '8';
		case graphics::SCANCODE_9: return '9';
		case graphics::SCANCODE_0: return '0';
		case graphics::SCANCODE_SPACE: return ' ';
		case graphics::SCANCODE_MINUS: return '-';
		case graphics::SCANCODE_EQUALS: return '=';
		case graphics::SCANCODE_LEFTBRACKET: return '[';
		case graphics::SCANCODE_RIGHTBRACKET: return ']';
		case graphics::SCANCODE_BACKSLASH: return '\\';
		case graphics::SCANCODE_SEMICOLON: return ';';
		case graphics::SCANCODE_APOSTROPHE: return '\'';
		case graphics::SCANCODE_GRAVE: return '`';
		case graphics::SCANCODE_COMMA: return ',';
		case graphics::SCANCODE_PERIOD: return '.';
		case graphics::SCANCODE_SLASH: return '/';
		default: return '\0';
		}
	}
	else
	{
		switch (key)
		{
		case graphics::SCANCODE_1: return '!';
		case graphics::SCANCODE_2: return '@';
		case graphics::SCANCODE_3: return '#';
		case graphics::SCANCODE_4: return '$';
		case graphics::SCANCODE_5: return '%';
		case graphics::SCANCODE_6: return '^';
		case graphics::SCANCODE_7: return '&';
		case graphics::SCANCODE_8: return '*';
		case graphics::SCANCODE_9: return '(';
		case graphics::SCANCODE_0: return ')';
		case graphics::SCANCODE_SPACE: return ' ';
		case graphics::SCANCODE_MINUS: return '_';
		case graphics::SCANCODE_EQUALS: return '+';
		case graphics::SCANCODE_LEFTBRACKET: return '{';
		case graphics::SCANCODE_RIGHTBRACKET: return '}';
		case graphics::SCANCODE_BACKSLASH: return '|';
		case graphics::SCANCODE_SEMICOLON: return ':';
		case graphics::SCANCODE_APOSTROPHE: return '"';
		case graphics::SCANCODE_GRAVE: return '~';
		case graphics::SCANCODE_COMMA: return '<';
		case graphics::SCANCODE_PERIOD: return '>';
		case graphics::SCANCODE_SLASH: return '?';
		default: return '\0';
		}
	}
}
bool isKeyJustPressed(graphics::scancode_t key)
{
	bool currentState = graphics::getKeyState(key);
	bool wasPressed = previousKeyStates[key];

	// Key is pressed now but wasn't pressed before
	return currentState && !wasPressed;
}

void updateKeyStates()
{
	// Update previous states for all keys
	for (int i = 0; i < graphics::NUM_SCANCODES; i++)
	{
		graphics::scancode_t key = static_cast<graphics::scancode_t>(i);
		previousKeyStates[key] = graphics::getKeyState(key);
	}
}
