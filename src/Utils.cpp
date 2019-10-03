//
// Created by Beef Erikson Studios on 10/3/2019.
//

#include "Utils.h"

bool Utils::init()
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
                std::cout << "SDL_image could not be initialized! SDL_image Error: %s\n";
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