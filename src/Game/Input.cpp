/*
//
// Created by Beef Erikson Studios on 10/3/2019.
//

#include "Input.h"

<<<<<<< HEAD
void Input::KeyPressed(unsigned int type, bool *quit, SDL_Event event, SDL_Surface gameKeyPressSurface)
=======
void Input::KeyPressed(unsigned int type, bool *quit, SDL_Event event, SDL_Texture *pGameKeyPressTextures,
        SDL_Texture *pGameTexture)
>>>>>>> e6c896af64c190d623e7f43091baa88b495f36ce
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
<<<<<<< HEAD
                gameCurrentSurface = gameKeyPressSurface[KEY_PRESS_SURFACE_UP];
=======
                pGameTexture = pGameKeyPressTextures[KEY_PRESS_SURFACE_UP];
>>>>>>> e6c896af64c190d623e7f43091baa88b495f36ce
                break;

            // Player moves down
            case SDLK_DOWN:
            case SDLK_s:
<<<<<<< HEAD
                gameCurrentSurface = gameKeyPressSurface[KEY_PRESS_SURFACE_DOWN];
=======
                pGameTexture = pGameKeyPressTextures[KEY_PRESS_SURFACE_DOWN];
>>>>>>> e6c896af64c190d623e7f43091baa88b495f36ce
                break;

            // Player moves left
            case SDLK_LEFT:
            case SDLK_a:
<<<<<<< HEAD
                gameCurrentSurface = gameKeyPressSurface[KEY_PRESS_SURFACE_LEFT];
=======
                pGameTexture = pGameKeyPressTextures[KEY_PRESS_SURFACE_LEFT];
>>>>>>> e6c896af64c190d623e7f43091baa88b495f36ce
                break;

            // Player moves right
            case SDLK_RIGHT:
            case SDLK_d:
<<<<<<< HEAD
                gameCurrentSurface = gameKeyPressSurface[KEY_PRESS_SURFACE_RIGHT];
                break;

            // Default player facing
            default:
                gameCurrentSuface = gameKeyPressSurface[KEY_PRESS_SURFACE_DEFAULT];
=======
                pGameTexture = pGameKeyPressTextures[KEY_PRESS_SURFACE_RIGHT];
>>>>>>> e6c896af64c190d623e7f43091baa88b495f36ce
                break;
        }
    }
}
*/
