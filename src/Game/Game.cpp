/*
//
// Created by Beef Erikson Studios on 10/3/2019.
//

#include "Game.h"

// Initializes window
bool Game::init(SDL_Window *pGameWindow, SDL_Renderer *pGameRenderer)
{
    // Initializes flag
    bool success = true;

    // Initializes SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        // Create window
        pGameWindow = SDL_CreateWindow(GAME_TITLE, 300, 300,
                                       SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (pGameWindow == nullptr)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Create renderer for window
            pGameRenderer = SDL_CreateRenderer(pGameWindow, -1, SDL_RENDERER_ACCELERATED);
            if (pGameRenderer == nullptr)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            } else {
                // Initialize renderer color
                SDL_SetRenderDrawColor(pGameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                // Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags)))
                {
                    printf("SDL_image could not be initialized! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

// Closes Game
void Game::close(SDL_Renderer *pGameRenderer, SDL_Window *pGameWindow)
{
    // Deallocate surfaces
    SDL_DestroyRenderer(pGameRenderer);
    pGameRenderer = nullptr;

    // Destroy window
    SDL_DestroyWindow(pGameWindow);
    pGameWindow = nullptr;

    // Quit SDL subsystems
    SDL_Quit();
}*/
