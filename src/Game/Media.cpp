/*
//
// Created by Beef Erikson Studios on 10/3/2019.
//
#include "Media.h"

// Loads individual image as texture
SDL_Texture *Media::loadTexture(SDL_Surface loadedSurface, SDL_Renderer *pGameRenderer, const std::string &path)
{
    // The final texture
    SDL_Texture* newTexture = nullptr;

    // Load image at specified path
    loadedSurface = IMG_Load(path.c_str());

    if (loadedSurface == nullptr)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(pGameRenderer, loadedSurface);

        if (newTexture == nullptr)
        {
            printf("Unable to create texture from %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
        }

        // Clean up old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

// loads media based on input
bool Media::loadMedia(SDL_Surface *pGameKeyPressSurface, SDL_Texture *pGameBackgroundTexture,
                      SDL_Renderer *pGameRenderer)
{
    // loading success flag
    bool success = true;

    // load default surface
    pGameKeyPressSurface[KeyPress::KEY_PRESS_SURFACE_DEFAULT] = loadTexture(pGameRenderer,
                                                                             "../sprites/player/playerDown.png");
    if (pGameKeyPressSurface[KeyPress::KEY_PRESS_SURFACE_DEFAULT] == nullptr)
    {
        printf("Unable to load default image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load up surface
    pGameKeyPressTextures[KeyPress::KEY_PRESS_SURFACE_UP] = loadTexture(pGameRenderer,
                                                                        "../sprites/player/playerUp.png");
    if (pGameKeyPressTextures[KeyPress::KEY_PRESS_SURFACE_UP] == nullptr)
    {
        printf("Unable to load up image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load down surface
    pGameKeyPressTextures[KeyPress::KEY_PRESS_SURFACE_DOWN] = loadTexture(pGameRenderer,
                                                                          "../sprites/player/playerDown.png");
    if (pGameKeyPressTextures[KeyPress::KEY_PRESS_SURFACE_DOWN] == nullptr)
    {
        printf("Unable to load down image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load left surface
    pGameKeyPressTextures[KeyPress::KEY_PRESS_SURFACE_LEFT] = loadTexture(pGameRenderer,
                                                                          "../sprites/player/playerLeft.png");
    if (pGameKeyPressTextures[KeyPress::KEY_PRESS_SURFACE_LEFT] == nullptr)
    {
        printf("Unable to load left image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load right surface
    pGameKeyPressTextures[KeyPress::KEY_PRESS_SURFACE_RIGHT] = loadTexture(pGameRenderer,
                                                                           "../sprites/player/playerRight.png");
    if (pGameKeyPressTextures[KeyPress::KEY_PRESS_SURFACE_RIGHT] == nullptr)
    {
        printf("Unable to load right image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load background surface
    *pGameBackgroundTexture = loadTexture(pGameRenderer,
                                          "../sprites/backgrounds/Greenlands 3.png");
    if (*pGameBackgroundTexture == nullptr)
    {
        printf("Unable to load background image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    return success;
}

// Stretches background image
SDL_Rect *Media::stretchBackground()
{
    Game game;
    SDL_Rect background;
    background.x = 0;
    background.y = 0;
    background.h = game.SCREEN_HEIGHT;
    background.w = game.SCREEN_WIDTH;
    return &background;
}
*/