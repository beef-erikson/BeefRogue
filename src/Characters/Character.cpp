//
// Created by Beef Erikson Studios on 10/11/2019.
//

#include "Character.h"

// Set sprite when facing up
void Character::set_facing_up(SDL_Texture *setFacingUp) {
    this->facingUp = setFacingUp;
}

// Set sprite when facing down
void Character::set_facing_down(SDL_Texture *setFacingDown) {
    this->facingDown = setFacingDown;
}

// Set sprite when facing right
void Character::set_facing_right(SDL_Texture *setFacingRight) {
    this->facingDown = setFacingRight;
}

// Set sprite when facing left
void Character::set_facing_left(SDL_Texture *setFacingLeft) {
    this->facingDown = setFacingLeft;
}