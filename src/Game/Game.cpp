//
// Created by Beef Erikson Studios on 10/20/2019.
//

#include "Game.h"

App app;

// Loads individual image as texture
SDL_Texture *Game::loadTexture(const std::string &path) {
    // The final texture
    SDL_Texture *newTexture{nullptr};

    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_Image error: %s\n", path.c_str(), IMG_GetError());
    }
    else {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(app.renderer, loadedSurface);
        if (newTexture == nullptr) {
            printf("Unable to create texture from %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
        }

        // Remove old surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}


// loads PNG files
bool Game::loadMedia() {
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


// Frees media and shuts down SDL
void Game::close() {
    // Free loaded images
    SDL_DestroyTexture(gTexturePlayer);
    SDL_DestroyTexture(gTextureBackground);
    gTexturePlayer = nullptr;
    gTextureBackground = nullptr;

    // Destroy window
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    app.renderer = nullptr;
    app.window = nullptr;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}


// Updates and draws to screen
void Game::render_update(SDL_Rect playerRect) {
    // Clear screen
    SDL_RenderClear(app.renderer);

    // Render background to screen
    SDL_RenderCopy(app.renderer, gTextureBackground, nullptr, nullptr);

    // Renders player to screen
    SDL_RenderCopy(app.renderer, gTexturePlayer, nullptr, &playerRect);

    // Update screen
    SDL_RenderPresent(app.renderer);
}


// Updates input
void Game::input_update(SDL_Event event, Character player, SDL_Rect *playerRect) {
    // Keyboard input detected
    if (event.type == SDL_KEYDOWN) {
        // Player hit key, change sprite based on input
        switch (event.key.keysym.sym) {
            case SDLK_UP:
            case SDLK_w:
                gTexturePlayer = loadTexture(player.get_facingUp());
                playerRect->y -= player.get_spriteHeight();
                break;
            case SDLK_DOWN:
            case SDLK_s:
                gTexturePlayer = loadTexture(player.get_facingDown());
                playerRect->y += player.get_spriteHeight();
                break;
            case SDLK_LEFT:
            case SDLK_a:
                gTexturePlayer = loadTexture(player.get_facingLeft());
                playerRect->x -= player.get_spriteWidth();
                break;
            case SDLK_RIGHT:
            case SDLK_d:
                gTexturePlayer = loadTexture(player.get_facingRight());
                playerRect->x += player.get_spriteWidth();
                break;
        }
    }
}