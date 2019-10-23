//
// Created by Beef Erikson Studios on 10/23/2019.
//

#ifndef BEEFROGUE_INPUTHANDLER_H
#define BEEFROGUE_INPUTHANDLER_H

#include "Command.h"

class InputHandler : public Command {
public:
    Command *getInputs(SDL_Event event);
    virtual void execute(Character &character);

private:
    Command *moveUp_;
    Command *moveDown_;
    Command *moveLeft_;
    Command *moveRight_;
};


#endif //BEEFROGUE_INPUTHANDLER_H
