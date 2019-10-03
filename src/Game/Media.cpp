//
// Created by Beef Erikson Studios on 10/3/2019.
//

#include "Media.h"

// loads media based on input
bool Media::loadMedia(SDL_Surface **pGameKeyPressSurfaces, SDL_Surface **pGameBackgroundSurface)
{
    // loading success flag
    bool success = true;

    // load default surface
    pGameKeyPressSurfaces[KeyPress::KEY_PRESS_SURFACE_DEFAULT] = loadSurface("../sprites/player/playerDown.png");
    if (pGameKeyPressSurfaces[KeyPress::KEY_PRESS_SURFACE_DEFAULT] == nullptr)
    {
        printf("Unable to load default image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load up surface
    pGameKeyPressSurfaces[KeyPress::KEY_PRESS_SURFACE_UP] = loadSurface("../sprites/player/playerUp.png");
    if (pGameKeyPressSurfaces[KeyPress::KEY_PRESS_SURFACE_UP] == nullptr)
    {
        printf("Unable to load up image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load down surface
    pGameKeyPressSurfaces[KeyPress::KEY_PRESS_SURFACE_DOWN] = loadSurface("../sprites/player/playerDown.png");
    if (pGameKeyPressSurfaces[KeyPress::KEY_PRESS_SURFACE_DOWN] == nullptr)
    {
        printf("Unable to load down image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load left surface
    pGameKeyPressSurfaces[KeyPress::KEY_PRESS_SURFACE_LEFT] = loadSurface("../sprites/player/playerLeft.png");
    if (pGameKeyPressSurfaces[KeyPress::KEY_PRESS_SURFACE_LEFT] == nullptr)
    {
        printf("Unable to load left image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load right surface
    pGameKeyPressSurfaces[KeyPress::KEY_PRESS_SURFACE_RIGHT] = loadSurface("../sprites/player/playerRight.png");
    if (pGameKeyPressSurfaces[KeyPress::KEY_PRESS_SURFACE_RIGHT] == nullptr)
    {
        printf("Unable to load right image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load background surface
    *pGameBackgroundSurface = loadSurface("../sprites/backgrounds/Greenlands 3.png");
    if (*pGameBackgroundSurface == nullptr)
    {
        printf("Unable to load background image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    return success;
}

// Loads image onto the surface
SDL_Surface *Media::loadSurface(const std::string &path)
{
    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr)
    {
        printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), IMG_GetError());
    }
    return loadedSurface;
}

// Stretches background image
SDL_Rect Media::stretchBackground()
{
    Game game;
    SDL_Rect background;
    background.x = 0;
    background.y = 0;
    background.h = game.SCREEN_HEIGHT;
    background.w = game.SCREEN_WIDTH;
    return background;
}