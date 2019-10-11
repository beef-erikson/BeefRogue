//
// Created by Beef Erikson Studios on 10/10/2019.
//

#ifndef BEEFROGUE_CHARACTER_H
#define BEEFROGUE_CHARACTER_H

#include <SDL.h>
#include <string>
#include <utility>

class Character {
public:
    // Constructors
    Character() = default;

    Character(std::string &facingUp,
              std::string &facingDown,
              std::string &facingLeft,
              std::string &facingRight,
              bool isNPC,
              int health) : facingUp_(facingUp), facingDown_(facingDown), facingLeft_(facingLeft),
                            facingRight_(facingRight), isNPC_(isNPC), health_(health) {};

    // Getters
    int get_health() { return health_; }

    bool get_is_npc() { return isNPC_; }

    const std::string *get_facingUp() { return &facingUp_; }

    const std::string *get_facingDown() { return &facingDown_; }

    const std::string *get_facingRight() { return &facingRight_; }

    const std::string *get_facingLeft() { return &facingLeft_; }

    // Setters
    void set_facing_up(const std::string &facingUp) { facingUp_ = facingUp; }

    void set_facing_down(const std::string &facingDown) { facingDown_ = facingDown; }

    void set_facing_left(const std::string &facingLeft) { facingLeft_ = facingLeft; }

    void set_facing_right(const std::string &facingRight) { facingRight_ = facingRight; }

    void set_is_NPC(bool isNPC) { isNPC_ = isNPC; };

    void set_health(int health) { health_ = health; };


protected:
    std::string facingUp_;
    std::string facingDown_;
    std::string facingLeft_;
    std::string facingRight_;
    bool isNPC_;
    int health_;
};

#endif //BEEFROGUE_CHARACTER_H