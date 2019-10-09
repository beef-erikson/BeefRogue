/*
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
    const static int SCREEN_WIDTH{800};
    const static int SCREEN_HEIGHT{600};
    const char* GAME_TITLE{"BeefRogue v2019.0.1"};

    // Initializes game
    bool init(SDL_Window *pGameWindow, SDL_Renderer *pGameRenderer);

    // Closes game
    void static close(SDL_Renderer *pGameRenderer, SDL_Window *pGameWindow);
};

#endif //BEEFROGUE_GAME_H*/
