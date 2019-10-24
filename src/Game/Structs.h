//
// Created by Beef Erikson Studios on 10/23/2019.
//

#ifndef BEEFROGUE_STRUCTS_H
#define BEEFROGUE_STRUCTS_H

// Holds common elements to App
typedef struct App {
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Texture *player;
    SDL_Texture *background;
    SDL_Event inputEvent;
} App;

#endif //BEEFROGUE_STRUCTS_H