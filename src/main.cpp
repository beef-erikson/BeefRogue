#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include "Utils.h"



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

// Starts SDL and creates window
bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

// Loads individual optimized image
SDL_Surface *loadSurface(const std::string &path);


Utils utils;


// The images that correspond to a keypress
SDL_Surface *gameKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

// Current displayed image
SDL_Surface *gameCurrentSurface = nullptr;

// Background image
SDL_Surface *gameBackgroundSurface = nullptr;



bool loadMedia()
{
    // loading success flag
    bool success = true;

    // load default surface
    gameKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("../sprites/player/playerDown.png");
    if (gameKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == nullptr)
    {
       std::cout << "Unable to load default image! SDL_Error: %s\n";
        success = false;
    }

    // load up surface
    gameKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("../sprites/player/playerUp.png");
    if (gameKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == nullptr)
    {
        printf("Unable to load up image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load down surface
    gameKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("../sprites/player/playerDown.png");
    if (gameKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == nullptr)
    {
        printf("Unable to load down image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load left surface
    gameKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("../sprites/player/playerLeft.png");
    if (gameKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == nullptr)
    {
        printf("Unable to load left image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load right surface
    gameKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("../sprites/player/playerRight.png");
    if (gameKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == nullptr)
    {
        printf("Unable to load right image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // load background surface
    gameBackgroundSurface = loadSurface("../sprites/backgrounds/Greenlands 3.png");
    if (gameBackgroundSurface == nullptr)
    {
        printf("Unable to load background image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    return success;
}

void close()
{
    // Deallocate surfaces
    SDL_FreeSurface(gameCurrentSurface);
    SDL_FreeSurface(gameBackgroundSurface);
    gameCurrentSurface = nullptr;
    gameBackgroundSurface = nullptr;

    // Destroy window
    SDL_DestroyWindow(utils.gameWindow);
    utils.gameWindow = nullptr;

    // Quit SDL subsystems
    SDL_Quit();
}

SDL_Surface *loadSurface(const std::string &path)
{
    // The final optimized image
    SDL_Surface *optimizedSurface = nullptr;

    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr)
    {
        printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), IMG_GetError());
    }
    return loadedSurface;
}

int main(int argc, char *args[])
{
    // Start up SDL and create window
    if (!utils.init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        // Load media
        if (!loadMedia())
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

            // Game loop
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
                stretchBackground.h = utils.SCREEN_HEIGHT;
                stretchBackground.w = utils.SCREEN_WIDTH;
                SDL_BlitScaled(gameBackgroundSurface, nullptr, utils.gameScreenSurface, &stretchBackground);

                // Apply the image
                SDL_BlitSurface(gameCurrentSurface, nullptr, utils.gameScreenSurface, nullptr);

                // Update the surface
                SDL_UpdateWindowSurface(utils.gameWindow);
            }
        }
    }

    // Free resources and close SDL
    close();

    return 0;
}