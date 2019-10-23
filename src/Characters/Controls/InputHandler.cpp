//
// Created by Beef Erikson Studios on 10/23/2019.
//

#include "InputHandler.h"

Command *InputHandler::getInputs(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        // Player hit key, change sprite based on input
        switch (event.key.keysym.sym) {
            case SDLK_UP:
            case SDLK_w:
                return moveUp_;
            case SDLK_DOWN:
            case SDLK_s:
                return moveDown_;
            case SDLK_LEFT:
            case SDLK_a:
                return moveLeft_;
            case SDLK_RIGHT:
            case SDLK_d:
                return moveRight_;
        }
    }
}

void InputHandler::execute(Character &character) {
    // nothing here yet, restructuring first
}