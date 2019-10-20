/*
//
// Created by Beef Erikson Studios on 10/20/2019.
//

#ifndef BEEFROGUE_COMMAND_H
#define BEEFROGUE_COMMAND_H

#include "Character.h"

// Command Class
class Command {
public:
    virtual ~Command() = default;
    virtual void execute(Character &character) = 0;
};


// Movement class
class MoveCommand : public Command {
public:
    // Constructor
    MoveCommand(MoveDirection direction, float distance, Character characterToMove);
    void execute(Character &character) override {
        character.move_up(); }

private:
    MoveDirection _direction;
    float _distance;
    Character _character;
};

#endif //BEEFROGUE_COMMAND_H*/
