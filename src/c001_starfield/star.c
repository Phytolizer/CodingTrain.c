#include "star.h"
#include "SDL_render.h"
#include "constants.h"
#include "helpers/math.h"
#include "helpers/random.h"

void Star_init(Star* s)
{
    s->x = rand_range((double)-WINDOW_WIDTH, (double)WINDOW_WIDTH);
    s->y = rand_range((double)-WINDOW_HEIGHT, (double)WINDOW_HEIGHT);
    s->z = rand_range((double)0, WINDOW_WIDTH);
    s->pz = s->z;
}

void Star_update(Star* s)
{
    s->z -= star_speed;
    if (s->z <= 0)
    {
        s->z = WINDOW_WIDTH;
        s->x = rand_range((double)-WINDOW_WIDTH, (double)WINDOW_WIDTH);
        s->y = rand_range((double)-WINDOW_HEIGHT, (double)WINDOW_HEIGHT);
        s->pz = s->z;
    }
}

void Star_show(Star* s, SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    double sx = math_map(s->x / s->z, 0, 1, 0, WINDOW_WIDTH);
    double sy = math_map(s->y / s->z, 0, 1, 0, WINDOW_HEIGHT);
    double r = math_map(s->z, 0, WINDOW_WIDTH, 16, 0);
    SDL_RenderDrawPoint(renderer, sx, sy);

    double px = math_map(s->x / s->pz, 0, 1, 0, WINDOW_WIDTH);
    double py = math_map(s->y / s->pz, 0, 1, 0, WINDOW_HEIGHT);
    s->pz = s->z;

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawLine(renderer, px, py, sx, sy);
}
