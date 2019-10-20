//
// Created by Beef Erikson Studios on 10/15/2019.
//

#ifndef BEEFROGUE_CHARACTER_H
#define BEEFROGUE_CHARACTER_H

#include <SDL.h>
#include <string>
#include <bits/stdc++.h>

class Character {
public:
    // Constructor
    Character(std::string &name,
              std::string &facingUp,
              std::string &facingDown,
              std::string &facingLeft,
              std::string &facingRight,
              int spriteHeight,
              int spriteWidth,
              bool isNPC,
              int health) : name_(name), facingUp_(facingUp), facingDown_(facingDown), facingLeft_(facingLeft),
                            facingRight_(facingRight), spriteHeight_(spriteHeight), spriteWidth_(spriteWidth),
                            isNPC_(isNPC), health_(health) {};

    //
    // Getters
    //
    std::string get_name() { return name_; }

    std::string get_facingUp() { return facingUp_; }

    std::string get_facingDown() { return facingDown_; }

    std::string get_facingRight() { return facingRight_; }

    std::string get_facingLeft() { return facingLeft_; }

    int get_spriteHeight() { return spriteHeight_; }

    int get_spriteWidth() { return spriteWidth_; }

    int get_health() { return health_; }

    bool get_is_npc() { return isNPC_; }

    //
    // Setters
    //
    void set_name(std::string &name) { name_ = name; }

    void set_facing_up(std::string &facingUp) { facingUp_ = facingUp; }

    void set_facing_down(std::string &facingDown) { facingDown_ = facingDown; }

    void set_facing_left(std::string &facingLeft) { facingLeft_ = facingLeft; }

    void set_facing_right(std::string &facingRight) { facingRight_ = facingRight; }

    void set_spriteHeight(int spriteHeight) { spriteHeight_ = spriteHeight; }

    void set_spriteWidth(int spriteWidth) { spriteWidth_ = spriteWidth; }

    void set_is_NPC(bool isNPC) { isNPC_ = isNPC; };

    void set_health(int health) { health_ = health; };

    // TODO make this happen.
    // Creates a Character object at the given x and y coordinates
    void create(int x, int y);

    // Movement controls
    void move_up();
    void move_down();
    void move_left();
    void move_right();

protected:
    // Character name
    std::string name_;

    // Sprites for directions
    std::string facingUp_;
    std::string facingDown_;
    std::string facingLeft_;
    std::string facingRight_;

    // Sprite dimensions
    int spriteHeight_;
    int spriteWidth_;

    // Is it an NPC?
    bool isNPC_;

    // Character health
    int health_;
};

#endif //BEEFROGUE_CHARACTER_H