//
// Created by Beef Erikson Studios on 10/12/2019.
//

#include "Player.h"

void Player::movePlayer(KeyPress direction, SDL_Texture *gTexture) {
    switch (direction) {
        // Up key image
        case KEY_PRESS_SURFACE_UP:
            gTexture = facingUp_;
            break;

        // Down key image
        case KEY_PRESS_SURFACE_DOWN:
            gTexture = facingDown_;
            break;

        // Left key image
        case KEY_PRESS_SURFACE_LEFT:
            gTexture = facingLeft_;
            break;

        // Right key image
        case KEY_PRESS_SURFACE_RIGHT:
            gTexture = facingRight_;
            break;

        // Default image
        case KEY_PRESS_SURFACE_DEFAULT:
            gTexture = facingDown_;
            break;
    }
}