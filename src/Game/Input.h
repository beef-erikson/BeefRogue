/*
//
// Created by Beef Erikson Studios on 10/3/2019.
//

#ifndef BEEFROGUE_INPUT_H
#define BEEFROGUE_INPUT_H

#include <SDL.h>

// Inputs
enum KeyPress
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT
};

class Input
{
public:
    // Handles the surface based on keypress
    SDL_Surface *gameKeyPressSurface = nullptr;

    // Handles keypress logic
    static void KeyPressed(unsigned int type, bool *quit, SDL_Event event, SDL_Surface gameKeyPressSurface);
};

#endif //BEEFROGUE_INPUT_H*/
