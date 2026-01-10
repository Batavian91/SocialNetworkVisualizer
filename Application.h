#pragma once
#include "GlobalState.h"

class Menu;

// implements GlobalState
class Application : public GlobalState
{
private:
	static Application* app_instance;
	Menu* menu;
	Application();
	~Application();
public:
	static Application* getInstance();
	static void deleteInstance();
	void init() override;
	void draw() override;
	void update() override;
};