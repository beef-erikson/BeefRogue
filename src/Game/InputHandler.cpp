//
// Created by Beef Erikson Studios on 10/22/2019.
//

#include "InputHandler.h"

Command *InputHandler::handleInput(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        // Player hit key, change sprite based on input
        switch (event.key.keysym.sym) {
            case SDLK_UP:
            case SDLK_w:
                return key_up_;
            case SDLK_DOWN:
            case SDLK_s:
                return key_down_;
            case SDLK_LEFT:
            case SDLK_a:
                return key_left_;
            case SDLK_RIGHT:
            case SDLK_d:
                return key_right_;
            default:
                return nullptr;
        }
    }
}