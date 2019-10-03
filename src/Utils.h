//
// Created by Beef Erikson Studios on 10/3/2019.
//

#ifndef BEEFROGUE_UTILS_H
#define BEEFROGUE_UTILS_H

#include <SDL.h>
#include <cstdio>
#include <SDL_image.h>
#include <iostream>

class Utils
{
public:
    //Screen constants
    const int SCREEN_WIDTH{800};
    const int SCREEN_HEIGHT{600};
    const char *const GAME_TITLE{"BeefRogue v2019.0.1"};

public:
    bool init();
    SDL_Window *gameWindow = nullptr;
    SDL_Surface *gameScreenSurface = nullptr;
};


#endif //BEEFROGUE_UTILS_H
