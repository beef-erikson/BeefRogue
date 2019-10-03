//
// Created by Beef Erikson Studios on 10/3/2019.
//

#include "Input.h"

void Input::KeyPressed(unsigned int type, bool *quit, SDL_Event event, SDL_Surface **gameKeyPressSurfaces,
        SDL_Surface *gameCurrentSurface)
{
    // User quit
    if (type == SDL_QUIT)
    {
        *quit = true;
    }

    // User presses a key
    if (type == SDL_KEYDOWN)
    {
        // Select surfaces based on key press
        switch (event.key.keysym.sym)
        {
            case SDLK_UP:
            case SDLK_w:
                *gameCurrentSurface = *gameKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
                break;

            case SDLK_DOWN:
            case SDLK_s:
                *gameCurrentSurface = *gameKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                break;

            case SDLK_LEFT:
            case SDLK_a:
                *gameCurrentSurface = *gameKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                break;

            case SDLK_RIGHT:
            case SDLK_d:
                *gameCurrentSurface = *gameKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                break;
        }
    }
}
