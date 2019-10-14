/*
//
// Created by Beef Erikson Studios on 10/12/2019.
//

#include "Player.h"


void Player::movePlayer(int direction, SDL_Texture *gTexture) {
    switch (direction) {
        // Up key image
        case 1:
            gTexture = facingUp_;
            break;

        // Down key image
        case 2:
            gTexture = facingDown_;
            break;

        // Left key image
        case 3:
            gTexture = facingLeft_;
            break;

        // Right key image
        case 4:
            gTexture = facingRight_;
            break;

        // Default image
        case 0:
            gTexture = facingDown_;
            break;
    }
}
*/
