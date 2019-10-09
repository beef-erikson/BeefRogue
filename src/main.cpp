//
// Created by Beef Erikson Studios on 10/9/2019.
//

#include <SDL.h>
<<<<<<< HEAD
#include <SDL_image.h>
#include <cstdio>
#include <string>
=======
#include <SDL2/SDL_image.h>
#include "Game.h"
#include "Media.h"
#include "Input.h"
>>>>>>> e6c896af64c190d623e7f43091baa88b495f36ce

// Screen dimension constants
const int SCREEN_WIDTH{640};
const int SCREEN_HEIGHT{480};

<<<<<<< HEAD
// Game name and version
const char *GAME_TITLE{"BeefRogue v2019.0.1"};

// Starts up SDL and creates window
bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

// Loads individual image as texture
SDL_Texture *loadTexture(const std::string &path);

// The window we'll be rendering to
SDL_Window *gWindow{nullptr};

// The window renderer
SDL_Renderer *gRenderer{nullptr};

// Current background texture
SDL_Texture *gBackgroundTexture{nullptr};

// Current displayed texture
SDL_Texture *gTexture{nullptr};

bool init() {
    // Initialization flag
    bool success{true};

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else {
        // Sets texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Warning: Linear texture filtering not enabled!");
        }

        // Creates window
        gWindow = SDL_CreateWindow(GAME_TITLE, 300, 300, SCREEN_WIDTH,
                                   SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == nullptr) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else {
            // Creates renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == nullptr) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else {
                // Initialize renderer color, in this case white (0xFFFFFFFF)
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                // Initialize PNG loading
                int imgFlags{IMG_INIT_PNG};
                if (!(IMG_Init(imgFlags))) {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia() {
    // Loading success flag
    bool success{true};

    // Load PNG texture
    gTexture = loadTexture("../sprites/player/playerDown.png");
    if (gTexture == nullptr) {
        printf("Failed to load texture image!\n");
        success = false;
=======
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
>>>>>>> e6c896af64c190d623e7f43091baa88b495f36ce
    }

    // Load background PNG texture
    gBackgroundTexture = loadTexture("../sprites/backgrounds/Greenlands 3.png");
    if (gBackgroundTexture == nullptr)
    {
<<<<<<< HEAD
        printf("Failed to load background texture image!\n");
        success = false;
    }
    return success;
}

void close() {
    // Free loaded images
    SDL_DestroyTexture(gTexture);
    SDL_DestroyTexture(gBackgroundTexture);
    gTexture = nullptr;
    gBackgroundTexture = nullptr;

    // Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture *loadTexture(const std::string &path) {
    // The final texture
    SDL_Texture *newTexture{nullptr};

    // Load image at specified path
    SDL_Surface *loadedSurface{IMG_Load(path.c_str())};
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == nullptr) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

int main(int argc, char *args[]) {
    // Start up SDL and create window
    if (!init()) {
        printf("Failed to initialize!\n");
    }
    else {
        // Load media
        if (!loadMedia()) {
            printf("Failed to load media!\n");
        }
        else {
            // Main loop flag
            bool quit{false};

            // Event handler
            SDL_Event event;

            //
            // Main game loop
            //
            while (!quit) {
                // Handle events on queue
                while (SDL_PollEvent(&event) != 0) {
                    // User requests quit
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                }
=======

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
>>>>>>> e6c896af64c190d623e7f43091baa88b495f36ce

                // Clears screen
                SDL_RenderClear(gRenderer);

                // Correctly scales and places player render
                SDL_Rect playerRect{0, 0, 46, 64};

<<<<<<< HEAD
                // Renders background to screen
                SDL_RenderCopy(gRenderer, gBackgroundTexture, nullptr, nullptr);

                // Renders texture to screen
                SDL_RenderCopy(gRenderer, gTexture, nullptr, &playerRect);

                // Update screen
                SDL_RenderPresent(gRenderer);
            }
=======
            // Update the surface
            SDL_UpdateWindowSurface(gameWindow);
>>>>>>> e6c896af64c190d623e7f43091baa88b495f36ce
        }
    }


    // Free resources and close SDL
<<<<<<< HEAD
    close();
=======
    Game::close(gameRenderer, gameWindow);
>>>>>>> e6c896af64c190d623e7f43091baa88b495f36ce

    return 0;
}