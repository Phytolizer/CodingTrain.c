#include <helpers/helpers.h>

int main(int argc, char** argv)
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    HELPERS_INIT("Starfield", 800, 600, window, renderer);

    HELPERS_CLEANUP();
    return 0;
}