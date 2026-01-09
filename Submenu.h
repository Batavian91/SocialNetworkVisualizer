#pragma once
#include <string>
#include "TextInput.h"

class Submenu
{
private:
	static Submenu* instance;
	std::string name;
	TextInput username_input;
	Submenu();
	~Submenu();
public:
	static Submenu* getInstance();
	static void releaseInstance();
	void setName(std::string&);
	std::string& getName();
	void draw();
	void update(float);
};