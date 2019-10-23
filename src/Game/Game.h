//
// Created by Beef Erikson Studios on 10/20/2019.
//
#ifndef BEEFROGUE_GAME_H
#define BEEFROGUE_GAME_H

#include "Common.h"
#include "Character.h"

class Game {
public:
    // Loads individual image as texture
    SDL_Texture *loadTexture(const std::string &path);

    // loads PNG files
    bool loadMedia();

    // Frees media and shuts down SDL
    void close();

    // Updates and draws to screen
    void render_update(SDL_Rect playerRect);

    // Updates input
    void input_update(SDL_Event event, Character player, SDL_Rect *playerRect);

public:
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