/*
//
// Created by Beef Erikson Studios on 10/18/2019.
//

#ifndef BEEFROGUE_INPUTHANDLER_H
#define BEEFROGUE_INPUTHANDLER_H

#include <SDL_events.h>
#include "Command.h"

class InputHandler {
public:
    Character *handleInput();

    // Keyboard input detected
    Command key_press(SDL_Event event);

private:
    Command *key_up_;
    Command *key_down_;
    Command *key_left_;
    Command *key_right_;
};


#endif //BEEFROGUE_INPUTHANDLER_H
*/
