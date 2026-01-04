//#include "Node.h"
//#include "Edge.h"
//#include <iostream>
//
//int main()
//{
//	Node n1;
//	Node n2;
//	Node n3;
//	Node n4;
//	Node n5;
//	Node n6;
//	Node n7;
//	Node n8;
//	Node n9;
//	Node n10;
//	Node n11;
//
//	Edge edge1;
//	Edge edge2;
//	Edge edge3;
//	Edge edge4;
//	Edge edge5;
//	Edge edge6;
//
//	return 0;
//}

#include "include/graphics.h"
#include "include/scancodes.h"

// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{
    graphics::MouseState mouse;
    graphics::getMouseState(mouse);
    if (mouse.button_left_released)
    {
        graphics::playSound("assets\\door2.wav", 1.0f, false);
    }
}

// The window content drawing function.
void draw()
{
    graphics::Brush br;

    graphics::setOrientation(45);

    br.texture = "assets\\boy2.png";
    br.outline_opacity = 0.0f;

    graphics::drawRect(500, 250, 200, 200, br);

    br.fill_color[0] = 0.5f;
    br.fill_color[1] = 0.0f;
    br.fill_color[2] = 0.0f;

    graphics::resetPose();
    drawText(300, 440, 70, "Hello World!", br);
}

int main()
{
    graphics::createWindow(1200, 600, "Hello World");

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(1000, 500);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::Brush br;
    br.fill_color[0] = 0.5f;
    br.fill_color[1] = 0.7f;
    br.fill_color[2] = 0.9f;
    graphics::setWindowBackground(br);

    graphics::setFont("assets\\orange juice 2.0.ttf");

    graphics::startMessageLoop();

    return 0;
}