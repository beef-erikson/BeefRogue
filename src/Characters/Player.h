//
// Created by Beef Erikson Studios on 10/11/2019.
//

#ifndef BEEFROGUE_PLAYER_H
#define BEEFROGUE_PLAYER_H

#include "Character.h"

class Player : public Character {
public:
    Player() = default;

    Player(std::string facingUp,
           std::string facingDown,
           std::string facingLeft,
           std::string facingRight,
           bool isNPC,
           int health) :
            Character(facingUp,
                      facingDown,
                      facingLeft,
                      facingRight,
                      isNPC,
                      health) {}
};

#endif //BEEFROGUE_PLAYER_H