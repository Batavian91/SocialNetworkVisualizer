#pragma once 
#include <graphics.h>
#include <string>
#include <vector>

class Select
{
private:
	graphics::Brush background_style;
	graphics::Brush text_style;
	std::vector<std::string> items;
	std::string selected_item;
public:
	Select();
	~Select();
	std::string getSelectedItem();
	void draw(float, float, float, float);
	void update(float);
};
