//
// Created by Beef Erikson Studios on 10/18/2019.
//

#include "InputHandler.h"

void InputHandler::handleInput() {
    if (isPressed(KEY_UP)) key_up_->execute();
    else if (isPressed(KEY_DOWN)) key_down_->execute();
    else if (isPressed(KEY_LEFT)) key_left_->execute();
    else if (isPressed(KEY_RIGHT)) key_right_->execute();
}