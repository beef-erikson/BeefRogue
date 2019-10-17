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
              int health) : m_name(name), m_facingUp(facingUp), m_facingDown(facingDown), m_facingLeft(facingLeft),
                            m_facingRight(facingRight), m_spriteHeight(spriteHeight), m_spriteWidth(spriteWidth),
                            m_isNPC(isNPC), m_health(health) {};

    //
    // Getters
    //
    std::string get_name() { return m_name; }

    std::string get_facingUp() { return m_facingUp; }

    std::string get_facingDown() { return m_facingDown; }

    std::string get_facingRight() { return m_facingRight; }

    std::string get_facingLeft() { return m_facingLeft; }

    int get_spriteHeight() { return m_spriteHeight; }

    int get_spriteWidth() { return m_spriteWidth; }

    int get_health() { return m_health; }

    bool get_is_npc() { return m_isNPC; }

    //
    // Setters
    //
    void set_name(std::string &name) { m_name = name; }

    void set_facing_up(std::string &facingUp) { m_facingUp = facingUp; }

    void set_facing_down(std::string &facingDown) { m_facingDown = facingDown; }

    void set_facing_left(std::string &facingLeft) { m_facingLeft = facingLeft; }

    void set_facing_right(std::string &facingRight) { m_facingRight = facingRight; }

    void set_spriteHeight(int spriteHeight) { m_spriteHeight = spriteHeight; }

    void set_spriteWidth(int spriteWidth) { m_spriteWidth = spriteWidth; }

    void set_is_NPC(bool isNPC) { m_isNPC = isNPC; };

    void set_health(int health) { m_health = health; };

    // TODO make this happen.
    // Creates a Character object at the given x and y coordinates
    void create(int x, int y);

protected:
    std::string m_name;
    std::string m_facingUp;
    std::string m_facingDown;
    std::string m_facingLeft;
    std::string m_facingRight;
    int m_spriteHeight;
    int m_spriteWidth;
    bool m_isNPC;
    int m_health;
};

#endif //BEEFROGUE_CHARACTER_H