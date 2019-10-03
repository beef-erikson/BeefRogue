//
// Created by Beef Erikson Studios on 10/3/2019.
//

#include "Media.h"

bool Media::loadMedia(SDL_Surface **pGameKeyPressSurfaces, SDL_Surface **pGameBackgroundSurface)
{
    // loading success flag
    bool success = true;

    // load default surface
    pGameKeyPressSurfaces[0] = loadSurface("../sprites/player/playerDown.png");
    if (pGameKeyPressSurfaces[0] == nullptr)
    {
        printf("Unable to load default image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load up surface
    pGameKeyPressSurfaces[1] = loadSurface("../sprites/player/playerUp.png");
    if (pGameKeyPressSurfaces[1] == nullptr)
    {
        printf("Unable to load up image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load down surface
    pGameKeyPressSurfaces[2] = loadSurface("../sprites/player/playerDown.png");
    if (pGameKeyPressSurfaces[2] == nullptr)
    {
        printf("Unable to load down image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load left surface
    pGameKeyPressSurfaces[3] = loadSurface("../sprites/player/playerLeft.png");
    if (pGameKeyPressSurfaces[3] == nullptr)
    {
        printf("Unable to load left image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load right surface
    pGameKeyPressSurfaces[4] = loadSurface("../sprites/player/playerRight.png");
    if (pGameKeyPressSurfaces[4] == nullptr)
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