//
// Created by Beef Erikson Studios on 10/15/2019.
//

#ifndef BEEFROGUE_CHARACTER_H
#define BEEFROGUE_CHARACTER_H

#include <SDL.h>
#include <string>
#include <Controls/Command.h>

class Character {
public:
    // Constructor
    Character(std::string name,
              std::string facingUp,
              std::string facingDown,
              std::string facingLeft,
              std::string facingRight,
              int xPosition,
              int yPosition,
              int spriteHeight,
              int spriteWidth,
              bool isNPC,
              int health) : name_(std::move(name)), facingUp_(std::move(facingUp)), facingDown_(std::move(facingDown)),
                            facingLeft_(std::move(facingLeft)), facingRight_(std::move(facingRight)),
                            x_(xPosition), y_(yPosition), spriteHeight_(spriteHeight), spriteWidth_(spriteWidth),
                            isNPC_(isNPC), health_(health) {};

    //
    // Getters
    //
    std::string get_name() { return name_; }

    std::string get_facingUp() { return facingUp_; }

    std::string get_facingDown() { return facingDown_; }

    std::string get_facingRight() { return facingRight_; }

    std::string get_facingLeft() { return facingLeft_; }

    int get_x_position() { return x_; }

    int get_y_position() { return y_; }

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

    void set_x_position(int xPosition) { x_ = xPosition; }

    void set_y_position(int yPosition) { y_ = yPosition; }

    void set_spriteHeight(int spriteHeight) { spriteHeight_ = spriteHeight; }

    void set_spriteWidth(int spriteWidth) { spriteWidth_ = spriteWidth; }

    void set_is_NPC(bool isNPC) { isNPC_ = isNPC; };

    void set_health(int health) { health_ = health; };

    //
    // Movement
    //
    void move_up();

private:
    // Character name
    std::string name_;

    // Sprites for directions
    std::string facingUp_;
    std::string facingDown_;
    std::string facingLeft_;
    std::string facingRight_;

    // Starting position
    int x_;
    int y_;

    // Sprite dimensions
    int spriteHeight_;
    int spriteWidth_;

    // Is it an NPC?
    bool isNPC_;

    // Character health
    int health_;
};

#endif //BEEFROGUE_CHARACTER_H