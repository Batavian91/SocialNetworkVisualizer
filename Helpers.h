#pragma once
#include "graphics.h"

graphics::scancode_t getKeyPressed();

char scancodeToChar(graphics::scancode_t key, bool shift); 
bool isKeyJustPressed(graphics::scancode_t key);
void updateKeyStates();