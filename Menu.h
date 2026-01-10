#pragma once
#include "Button.h"

class Menu
{
private:
	Button** buttons;
public:
	Menu();
	~Menu();
	void draw();
	void update();
};