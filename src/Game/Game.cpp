//
// Created by Beef Erikson Studios on 10/3/2019.
//

#include "Game.h"

// Initializes window
bool Game::init()
{
    // Initialises flag
    bool success = true;

    // Initialises SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        // Create window
        gameWindow = SDL_CreateWindow(GAME_TITLE, 300, 300,
                                      SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gameWindow == nullptr)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags)))
            {
                printf("SDL_image could not be initialized! SDL_image Error: %s\n", IMG_GetError());
                success = false;
            }
            else
            {
                // Get window surface
                gameScreenSurface = SDL_GetWindowSurface(gameWindow);
            }
        }
    }

    return success;
}

// Ignored UnusedValue as it is actually being used to clear memory (setting the pointers to null)
#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
// Closes Game
void Game::close(SDL_Surface *pGameCurrentSurface, SDL_Surface *pGameBackgroundSurface)
{
    // Deallocate surfaces
    SDL_FreeSurface(pGameCurrentSurface);
    SDL_FreeSurface(pGameBackgroundSurface);
    pGameCurrentSurface = nullptr;
    pGameBackgroundSurface = nullptr;

    // Destroy window
    SDL_DestroyWindow(gameWindow);
    gameWindow = nullptr;

    // Quit SDL subsystems
    SDL_Quit();
}
#pragma clang diagnostic pop