#include <iostream>
#include "SDL.h"

//Screen constants
const int SCREEN_WIDTH{800};
const int SCREEN_HEIGHT{600};
const char *const GAME_TITLE{"BeefRogue v2019.0.1"};

// Starts SDL and creates window
bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

// The window we'll be rendering to
SDL_Window *gameWindow = nullptr;

// The surface contained by the window
SDL_Surface *gameScreenSurface = nullptr;

// The image we will load and show on the screen
SDL_Surface *gamePlayer = nullptr;

bool init() {
    // Initialises flag
    bool success = true;

    // Initialises SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    } else {
        // Create window
        gameWindow = SDL_CreateWindow(GAME_TITLE, 300, 300,
                                      SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gameWindow == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        } else {
            // Get window surface
            gameScreenSurface = SDL_GetWindowSurface(gameWindow);
        }
    }

    return success;
}

bool loadMedia()
{
    // loading success flag
    bool success = true;

    // load splash image
    gamePlayer = SDL_LoadBMP("../sprites/player.bmp");
    if (gamePlayer == nullptr)
    {
        printf("Unable to load image %s! SDL_Error: %s\n", "../sprites/player.bmp", SDL_GetError());
        success = false;
    }

    return success;
}

void close()
{
    // Deallocate surface
    SDL_FreeSurface(gamePlayer);
    gamePlayer = nullptr;

    // Destroy window
    SDL_DestroyWindow(gameWindow);
    gameWindow = nullptr;

    // Quit SDL subsystems
    SDL_Quit();
}

int main(int argc, char *args[]) {
    // Start up SDL and create window
    if (!init())
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
    }

    // Main loop flag
    bool quit = false;

    // Event handler
    SDL_Event event;

    // Game loop
    while (!quit)
    {
        // Handle events on queue
        while (SDL_PollEvent(&event) != 0)
        {
            // User requests quit
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Apply the image
        SDL_BlitSurface(gamePlayer, nullptr, gameScreenSurface, nullptr);

        // Update the surface
        SDL_UpdateWindowSurface(gameWindow);
    }

    // Free resources and close SDL
    close();

    return 0;
}