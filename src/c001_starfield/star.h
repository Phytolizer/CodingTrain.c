#pragma once

#include <SDL_render.h>

typedef struct
{
    double x;
    double y;
    double z;
    double pz;
} Star;

void Star_init(Star* s);
void Star_update(Star* s);
void Star_show(Star* s, SDL_Renderer* renderer);