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
    virtual void execute() = 0;

protected:
    Command() = default;
};

#endif //BEEFROGUE_COMMAND_H