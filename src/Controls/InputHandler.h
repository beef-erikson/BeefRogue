//
// Created by Beef Erikson Studios on 10/23/2019.
//

#ifndef BEEFROGUE_INPUTHANDLER_H
#define BEEFROGUE_INPUTHANDLER_H

#include "Command.h"
#include "Common.h"

class InputHandler : public Command {
public:
    Command *getInputs(SDL_Event event);
    void handleInput();

private:
    Command *moveUp_;
    Command *moveDown_;
    Command *moveLeft_;
    Command *moveRight_;
};


#endif //BEEFROGUE_INPUTHANDLER_H