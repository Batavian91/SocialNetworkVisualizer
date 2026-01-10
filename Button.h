#pragma once
#include "Rectangle.h"
#include "VisualAsset.h"

class Button : public Rectangle, public VisualAsset
{
private:
	const std::string BUTTON_TEXT;
	graphics::Brush text_style;
public:
	Button();
	Button(float, float, float, float,
		const std::string&);
	~Button();
	float getTextX(float) const;
	float getTextY(float, float) const;
	void draw() override;
};