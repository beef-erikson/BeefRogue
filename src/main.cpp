#include <cstdio>
#include <SDL.h>
#include "Game.h"
#include "Media.h"

Game game;
Media media;
// Inputs
enum KeyPress
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

// The images that correspond to a keypress
SDL_Surface *gameKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

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
        gameCurrentSurface = gameKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

        // Main Game loop
        while (!quit)
        {
            // Handle events on queue
            while (SDL_PollEvent(&event) != 0)
            {
                // User requests quit
                if (event.type == SDL_QUIT)
                {
                    quit = true;
                }
                    // User presses a key
                else if (event.type == SDL_KEYDOWN)
                {
                    // Select surfaces based on key press
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_UP:
                        case SDLK_w:
                            gameCurrentSurface = gameKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
                            break;

                        case SDLK_DOWN:
                        case SDLK_s:
                            gameCurrentSurface = gameKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                            break;

                        case SDLK_LEFT:
                        case SDLK_a:
                            gameCurrentSurface = gameKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                            break;

                        case SDLK_RIGHT:
                        case SDLK_d:
                            gameCurrentSurface = gameKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                            break;
                    }
                }
            }

            // Apply stretched background
            SDL_Rect stretchBackground;
            stretchBackground.x = 0;
            stretchBackground.y = 0;
            stretchBackground.h = game.SCREEN_HEIGHT;
            stretchBackground.w = game.SCREEN_WIDTH;
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