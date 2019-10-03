//
// Created by Beef Erikson Studios on 10/3/2019.
//

#ifndef BEEFROGUE_MEDIA_H
#define BEEFROGUE_MEDIA_H

#include <SDL_image.h>
#include <string>

class Media
{
public:
    static bool loadMedia(SDL_Surface **pGameKeyPressSurfaces, SDL_Surface **pGameBackgroundSurface);
    static SDL_Surface *loadSurface(const std::string &path);
};


#endif //BEEFROGUE_MEDIA_H
