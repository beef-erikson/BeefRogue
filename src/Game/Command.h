//
// Created by Beef Erikson Studios on 10/22/2019.
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

//
// Movement classes
//
class MoveUpCommand : public Command {
public:
    void execute(Character &character) override {
        character.move_up(character);
    };
};

class MoveDownCommand : public Command {
public:
    void execute(Character &character) override {
        character.move_down(character);
    };
};
class MoveLeftCommand : public Command {
public:
    void execute(Character &character) override {
        character.move_left(character);
    };
};
class MoveRightCommand : public Command {
public:
    void execute(Character &character) override {
        character.move_right(character);
    };
};

#endif //BEEFROGUE_COMMAND_H
