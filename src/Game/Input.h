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
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

class Input
{
public:
    static void KeyPressed(unsigned int type, bool *quit, SDL_Event event, SDL_Texture *pGameKeyPressTextures,
            SDL_Texture *pGameTexture);
};

#endif //BEEFROGUE_INPUT_H