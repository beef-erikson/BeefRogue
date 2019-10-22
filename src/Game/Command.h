
//
// Created by Beef Erikson Studios on 10/20/2019.
//

#ifndef BEEFROGUE_COMMAND_H
#define BEEFROGUE_COMMAND_H

#include "Character.h"
#include "Movement.h"

// Command Class
class Command {
public:
    virtual ~Command() = default;
    virtual void execute(Character &character) = 0;
};

// Movement class
class MoveUpCommand : public Command {
public:
    virtual void execute(Movement::MoveDirection direction, int distance, Character &character);


private:
    Movement::MoveDirection direction_;
    int distance_;
    Character character_;
};

#endif //BEEFROGUE_COMMAND_H
