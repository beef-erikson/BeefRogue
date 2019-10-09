#include <cstdio>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.h"
#include "Media.h"
#include "Input.h"

Game game;

// The textures that correspond to a keypress
SDL_Texture *gameKeyPress[KeyPress::KEY_PRESS_SURFACE_TOTAL];

//Current displayed texture
SDL_Texture *gameTexture = nullptr;

// Loads background image as texture
SDL_Texture *backgroundTexture;

//Loads individual image as texture
SDL_Texture *loadTexture( std::string path );

//The window we'll be rendering to
SDL_Window *gameWindow = nullptr;

//The window renderer
SDL_Renderer *gameRenderer = nullptr;

int main(int argc, char *args[])
{
    // Start up SDL and create window
    if (!game.init(gameWindow, gameRenderer))
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        if (!Media::loadMedia(gameKeyPressSurfaces, &gameBackgroundSurface))

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
            SDL_UpdateWindowSurface(gameWindow);
        }
    }


    // Free resources and close SDL
    Game::close(gameRenderer, gameWindow);

    return 0;
}