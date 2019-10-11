//
// Created by Beef Erikson Studios on 10/11/2019.
//

#ifndef BEEFROGUE_PLAYER_H
#define BEEFROGUE_PLAYER_H

#include "Character.h"

class Player : public Character {
public:
    Player() = default;

    Player(SDL_Texture *facingUp,
           SDL_Texture *facingDown,
           SDL_Texture *facingRight,
           SDL_Texture *facingLeft,
           bool isNPC,
           int health) :
            Character(facingUp,
                      facingDown,
                      facingRight,
                      facingLeft,
                      isNPC,
                      health) {}
};

#endif //BEEFROGUE_PLAYER_H