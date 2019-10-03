#include <cstdio>
#include <SDL.h>
#include "Game.h"
#include "Media.h"
#include "Input.h"

Game game;

// The images that correspond to a keypress
SDL_Surface *gameKeyPressSurfaces[KeyPress::KEY_PRESS_SURFACE_TOTAL];

// Current displayed image
SDL_Surface *gameCurrentSurface = nullptr;

// Background image
SDL_Surface *gameBackgroundSurface = nullptr;

int main(int argc, char *args[])
{
    // Start up SDL and create window
    if (!game.init())
    {
        printf("Failed to initialize!\n");
    }
    else if (!Media::loadMedia(gameKeyPressSurfaces, &gameBackgroundSurface))
    {
        printf("Failed to load media!\n");
    }
    else
    {
        // Main loop flag
        bool quit = false;

        // Event handler
        SDL_Event event;

        // Set default surface to display
        gameCurrentSurface = gameKeyPressSurfaces[KeyPress::KEY_PRESS_SURFACE_DEFAULT];

        //
        // Main Game loop
        //
        while (!quit)
        {
            // Handle events on queue
            while (SDL_PollEvent(&event) != 0)
            {
                // Handles keyboard input
                Input::KeyPressed(event.type, &quit, event, gameKeyPressSurfaces, gameCurrentSurface);
            }

            // Apply stretched background
            SDL_Rect stretchBackground = Media::stretchBackground();
            SDL_BlitScaled(gameBackgroundSurface, nullptr, game.gameScreenSurface, &stretchBackground);

            // Apply the image
            SDL_BlitSurface(gameCurrentSurface, nullptr, game.gameScreenSurface, nullptr);

            // Update the surface
            SDL_UpdateWindowSurface(game.gameWindow);
        }
    }

    // Free resources and close SDL
    game.close(gameCurrentSurface, gameBackgroundSurface);

    return 0;
}