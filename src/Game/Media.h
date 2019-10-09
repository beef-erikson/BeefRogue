/*
//
// Created by Beef Erikson Studios on 10/3/2019.
//
#ifndef BEEFROGUE_MEDIA_H
#define BEEFROGUE_MEDIA_H

#include <SDL_image.h>
#include <string>
#include "Game.h"
#include "Input.h"

class Media
{
public:
    // Loads background
    void loadBackground(SDL_Surface backgroundSurface);

    // Loads individual image as texture
    SDL_Texture *loadTexture(SDL_Surface loadedSurface, SDL_Renderer *pGameRenderer, const std::string &path);

    bool loadMedia(SDL_Surface *pGameKeyPressSurface, SDL_Texture *pGameBackgroundTexture,
                          SDL_Renderer *pGameRenderer);

    static SDL_Rect *stretchBackground();
};

#endif //BEEFROGUE_MEDIA_H
*/