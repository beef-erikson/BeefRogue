//
// Created by Beef Erikson Studios on 10/14/2019.
//

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <cstdio>
#include "Player.h"

// Window parameters
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const char *GAME_NAME = "BeefRogue v2019.0.1";

// Starts SDL and creates window
bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

// The window to render to
SDL_Window *gWindow{nullptr};

// The window renderer
SDL_Renderer *gRenderer{nullptr};

// Loads individual image as texture
SDL_Texture *loadTexture(const std::string &path);

// Current displayed player texture
SDL_Texture *gTexturePlayer{nullptr};

// Current displayed background texture
SDL_Texture *gTextureBackground{nullptr};

bool init() {
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else {
        // Create window
        gWindow = SDL_CreateWindow(GAME_NAME, 300, 300, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else {
            // Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == nullptr) {
                printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
                success = false;
            }
            else {
                // Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                // Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags))) {
                    printf("SDL_Image could not initialize! SDL_Image error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}


SDL_Texture *loadTexture(const std::string &path) {
    // The final texture
    SDL_Texture *newTexture{nullptr};

    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_Image error: %s\n", path.c_str(), IMG_GetError());
    }
    else {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == nullptr) {
            printf("Unable to create texture from %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
        }

        // Remove old surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}


bool loadMedia() {
    // Loading success flag
    bool success = true;

    // Load PNG player
    gTexturePlayer = loadTexture("../sprites/player/playerDown.png");
    if (gTexturePlayer == nullptr) {
        printf("Failed to load player image!\n");
        success = false;
    }

    // Load PNG background
    gTextureBackground = loadTexture("../sprites/backgrounds/Greenlands 3.png");
    if (gTextureBackground == nullptr) {
        printf("Failed to load background image!\n");
        success = false;
    }

    return success;
}


void close() {
    // Free loaded images
    SDL_DestroyTexture(gTexturePlayer);
    SDL_DestroyTexture(gTextureBackground);
    gTexturePlayer = nullptr;
    gTextureBackground = nullptr;

    // Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gRenderer = nullptr;
    gWindow = nullptr;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}


int main(int argc, char *args[]) {
    // Start up SDL and create window
    if (!init()) {
        printf("Failed to initialize!");
    }
    else {
        // Load media
        if (!loadMedia()) {
            printf("Failed to load media!");
        }
        else {
            // Main loop flag
            bool quit = false;

            // Event handler
            SDL_Event event;

            // Create Player
            Player player("Beef",
                          "../sprites/player/playerUp.png",
                          "../sprites/player/playerDown.png",
                          "../sprites/player/playerLeft.png",
                          "../sprites/player/playerRight.png",
                          64,
                          46,
                          false,
                          100);

            // Player rectangle size, center of screen
            SDL_Rect playerRect{SCREEN_WIDTH / 2 - player.get_spriteWidth() / 2,
                                 SCREEN_HEIGHT / 2 - player.get_spriteHeight() / 2,
                                 player.get_spriteWidth(), player.get_spriteHeight()};

            ///
            /// MAIN GAME LOOP
            ///
            while (!quit) {
                // Handle events
                while (SDL_PollEvent(&event) != 0) {
                    // Quits game if X is clicked
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }

                    // Keyboard input detected
                    if (event.type == SDL_KEYDOWN) {
                        // Player hit key, change sprite based on input
                        switch (event.key.keysym.sym) {
                            case SDLK_UP:
                            case SDLK_w:
                                gTexturePlayer = loadTexture(player.get_facingUp());
                                playerRect.y -= player.get_spriteHeight();
                                break;
                            case SDLK_DOWN:
                            case SDLK_s:
                                gTexturePlayer = loadTexture(player.get_facingDown());
                                playerRect.y += player.get_spriteHeight();
                                break;
                            case SDLK_LEFT:
                            case SDLK_a:
                                gTexturePlayer = loadTexture(player.get_facingLeft());
                                playerRect.x -= player.get_spriteWidth();
                                break;
                            case SDLK_RIGHT:
                            case SDLK_d:
                                gTexturePlayer = loadTexture(player.get_facingRight());
                                playerRect.x += player.get_spriteWidth();
                                break;
                        }
                    }
                }

                // Clear screen
                SDL_RenderClear(gRenderer);

                // Render background to screen
                SDL_RenderCopy(gRenderer, gTextureBackground, nullptr, nullptr);

                // Renders player to screen
                SDL_RenderCopy(gRenderer, gTexturePlayer, nullptr, &playerRect);

                // Update screen
                SDL_RenderPresent(gRenderer);
            }

            ///
            /// End Main Game Loop
            ///
        }
    }

    close();
    return 0;
}