/*
//
// Created by Beef Erikson Studios on 10/18/2019.
//

#include "InputHandler.h"

Command InputHandler::*handleInput() {
    if (isPressed(KEY_UP)) return key_up_;
    if (isPressed(KEY_DOWN)) return key_down_;
    if (isPressed(KEY_LEFT)) return key_left_;
    if (isPressed(KEY_RIGHT)) return key_right_;

    // Nothing pressed
    return nullptr;
}

Command InputHandler::key_press(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        // Player hit key, change sprite based on input
        switch (event.key.keysym.sym) {
            case SDLK_UP:
            case SDLK_w:
                return key_up_;
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
*/
