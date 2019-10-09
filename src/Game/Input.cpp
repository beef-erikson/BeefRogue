/*
//
// Created by Beef Erikson Studios on 10/3/2019.
//

#include "Input.h"

void Input::KeyPressed(unsigned int type, bool *quit, SDL_Event event, SDL_Surface gameKeyPressSurface)
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
            // Player moves up
            case SDLK_UP:
            case SDLK_w:
                gameCurrentSurface = gameKeyPressSurface[KEY_PRESS_SURFACE_UP];
                break;

            // Player moves down
            case SDLK_DOWN:
            case SDLK_s:
                gameCurrentSurface = gameKeyPressSurface[KEY_PRESS_SURFACE_DOWN];
                break;

            // Player moves left
            case SDLK_LEFT:
            case SDLK_a:
                gameCurrentSurface = gameKeyPressSurface[KEY_PRESS_SURFACE_LEFT];
                break;

            // Player moves right
            case SDLK_RIGHT:
            case SDLK_d:
                gameCurrentSurface = gameKeyPressSurface[KEY_PRESS_SURFACE_RIGHT];
                break;

            // Default player facing
            default:
                gameCurrentSuface = gameKeyPressSurface[KEY_PRESS_SURFACE_DEFAULT];
                break;
        }
    }
}
*/
