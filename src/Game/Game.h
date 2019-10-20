//
// Created by Beef Erikson Studios on 10/20/2019.
//
#ifndef BEEFROGUE_GAME_H
#define BEEFROGUE_GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>
#include <string>
#include "Player.h"

class Game {
public:
    // Starts SDL and creates window
    bool init();

    // Loads individual image as texture
    SDL_Texture *loadTexture(const std::string &path);

    // loads PNG files
    bool loadMedia();

    // Frees media and shuts down SDL
    void close();

    // Updates and draws to screen
    void render_update(SDL_Rect playerRect);

    // Updates input
    void input_update(SDL_Event event, Player player, SDL_Rect *playerRect);

public:
    // Window parameters
    int screen_width = 640;
    int screen_height = 480;
    const char *GAME_NAME = "BeefRogue v2019.0.1";

    // Current displayed player texture
    SDL_Texture *gTexturePlayer{nullptr};

    // Current displayed background texture
    SDL_Texture *gTextureBackground{nullptr};

    // The window to render to
    SDL_Window *gWindow{nullptr};

    // The window renderer
    SDL_Renderer *gRenderer{nullptr};
};

#endif //BEEFROGUE_GAME_H