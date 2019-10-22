//
// Created by Beef Erikson Studios on 10/20/2019.
//

#ifndef BEEFROGUE_MOVEMENT_H
#define BEEFROGUE_MOVEMENT_H


class Movement {
public:
    enum MoveDirection {
        MOVE_UP,
        MOVE_DOWN,
        MOVE_RIGHT,
        MOVE_LEFT
    };

public:
    void move_up();
    void move_down();
    void move_left();
    void move_right();
};


#endif //BEEFROGUE_MOVEMENT_H
