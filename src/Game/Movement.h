//
// Created by Beef Erikson Studios on 10/18/2019.
//

#ifndef BEEFROGUE_MOVEMENT_H
#define BEEFROGUE_MOVEMENT_H

#include "Command.h"

class Movement {
    class MoveUp : public Command {
    public:
        virtual void execute(Character &character) {
            character.move_up(); }
    };
    class MoveDown : public Command {
    public:
        virtual void execute(Character &character) {
            character.move_down(); }
    };
    class MoveLeft : public Command {
    public:
        virtual void execute(Character &character) {
            character.move_left(); }
    };
    class MoveRight : public Command {
    public:
        virtual void execute(Character &character) {
            character.move_right(); }
    };
};


#endif //BEEFROGUE_MOVEMENT_H
