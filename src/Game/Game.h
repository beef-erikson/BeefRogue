//
// Created by Beef Erikson Studios on 10/3/2019.
//

#ifndef BEEFROGUE_GAME_H
#define BEEFROGUE_GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>

class Game
{
public:
    //Screen constants
    const int SCREEN_WIDTH{800};
    const int SCREEN_HEIGHT{600};
    const char *const GAME_TITLE{"BeefRogue v2019.0.1"};

    // SDL Variables
    SDL_Window *gameWindow = nullptr;
    SDL_Surface *gameScreenSurface = nullptr;

    // Initializes game
    bool init();

    // Closes game
    void close(SDL_Surface *pGameCurrentSurface, SDL_Surface *pGameBackgroundSurface);
};

#endif //BEEFROGUE_GAME_H