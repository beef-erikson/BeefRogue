//
// Created by Beef Erikson Studios on 10/10/2019.
//

#include "Character.h"

// Constructor with sprites and isNPC properties
Character::Character(SDL_Texture *facingUp, SDL_Texture *facingDown, SDL_Texture *facingRight,
                     SDL_Texture *facingLeft, bool isNPC) {
    facingUp = this->facingUp;
    facingDown = this->facingDown;
    facingRight = this->facingRight;
    facingLeft = this->facingLeft;
    isNPC = this->isNPC;
}

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