#include <helpers/helpers.h>

int main(int argc, char** argv)
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    HELPERS_INIT("Starfield", 800, 600, window, renderer);

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