//
// Created by Beef Erikson Studios on 10/3/2019.
//

#include "Input.h"

void Input::KeyPressed(unsigned int type, bool *quit, SDL_Event event, SDL_Texture *pGameKeyPressTextures,
        SDL_Texture *pGameTexture)
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
                pGameTexture = pGameKeyPressTextures[KEY_PRESS_SURFACE_UP];
                break;

            case SDLK_DOWN:
            case SDLK_s:
                pGameTexture = pGameKeyPressTextures[KEY_PRESS_SURFACE_DOWN];
                break;

            case SDLK_LEFT:
            case SDLK_a:
                pGameTexture = pGameKeyPressTextures[KEY_PRESS_SURFACE_LEFT];
                break;

            case SDLK_RIGHT:
            case SDLK_d:
                pGameTexture = pGameKeyPressTextures[KEY_PRESS_SURFACE_RIGHT];
                break;
        }
    }
}
