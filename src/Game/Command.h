//
// Created by Beef Erikson Studios on 10/18/2019.
//

#ifndef BEEFROGUE_COMMAND_H
#define BEEFROGUE_COMMAND_H

#include "Character.h"

class Command {
public:
    virtual ~Command() {}
    virtual void execute(Character &character) = 0;
};

#endif //BEEFROGUE_COMMAND_H
