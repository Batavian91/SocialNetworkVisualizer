#pragma once
#include <string>

class Submenu
{
private:
	static Submenu* instance;
	std::string name;
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