//
// Created by Beef Erikson Studios on 10/10/2019.
//

#ifndef BEEFROGUE_CHARACTER_H
#define BEEFROGUE_CHARACTER_H

#include <SDL.h>

class Character {
public:
    // Constructors
    Character()= default;

    Character(SDL_Texture *facingUp,
              SDL_Texture *facingDown,
              SDL_Texture *facingRight,
              SDL_Texture *facingLeft,
              bool isNPC);

    // Getters
    int get_health() { return health; };
    bool get_is_npc() { return isNPC; };
    SDL_Texture *get_facingUp() { return facingUp; };
    SDL_Texture *get_facingDown() { return facingDown; };
    SDL_Texture *get_facingRight() { return facingRight; };
    SDL_Texture *get_facingLeft() { return facingLeft; };

    // Setters
    void set_facing_up(SDL_Texture *setFacingUp);
    void set_facing_down(SDL_Texture *setFacingDown);
    void set_facing_right(SDL_Texture *setFacingRight);
    void set_facing_left(SDL_Texture *setFacingLeft);
    void set_is_NPC(bool setIsNPC) { isNPC = setIsNPC; };
    void set_health(int setHealth) { health = setHealth; };


protected:
    SDL_Texture *facingUp{};
    SDL_Texture *facingDown{};
    SDL_Texture *facingRight{};
    SDL_Texture *facingLeft{};
    bool isNPC{};
    int health{};
};

#endif //BEEFROGUE_CHARACTER_H