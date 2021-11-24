#include "constants.h"
#include <helpers/helpers.h>

int main(int argc, char** argv)
{
    HELPERS_INIT("Starfield", WINDOW_WIDTH, WINDOW_HEIGHT, 0);

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

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    HELPERS_CLEANUP();
    return 0;
}