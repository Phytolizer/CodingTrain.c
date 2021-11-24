#include "constants.h"
#include "star.h"
#include <helpers/helpers.h>

double star_speed = 0.5;
#define STAR_COUNT 800

int main(int argc, char** argv)
{
    HELPERS_INIT("Starfield", WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    Star stars[STAR_COUNT];
    for (int i = 0; i < STAR_COUNT; i++)
    {
        Star_init(&stars[i]);
    }

    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                break;
            }
        }

        for (int i = 0; i < STAR_COUNT; i++)
        {
            Star_update(&stars[i]);
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < STAR_COUNT; i++)
        {
            Star_show(&stars[i], renderer);
        }
        SDL_RenderPresent(renderer);
    }

    HELPERS_CLEANUP();
    return 0;
}