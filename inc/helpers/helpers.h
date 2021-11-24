#pragma once
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>

/// Initialize a window and renderer with SDL.
///
/// Places `window` and `renderer` in the current scope.
///
/// Returns from the function with a value of 1 if initialization fails.
#define HELPERS_INIT(Title, Width, Height)                                                                             \
    SDL_Window* window;                                                                                                \
    SDL_Renderer* renderer;                                                                                            \
    do                                                                                                                 \
    {                                                                                                                  \
        if (SDL_Init(SDL_INIT_VIDEO) != 0)                                                                             \
        {                                                                                                              \
            printf("SDL_Init Error: %s\n", SDL_GetError());                                                            \
            return 1;                                                                                                  \
        }                                                                                                              \
        window = SDL_CreateWindow(Title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height,              \
                                  SDL_WINDOW_SHOWN);                                                                   \
        if (window == NULL)                                                                                            \
        {                                                                                                              \
            printf("SDL_CreateWindow Error: %s\n", SDL_GetError());                                                    \
            SDL_Quit();                                                                                                \
            return 1;                                                                                                  \
        }                                                                                                              \
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);               \
        if (renderer == NULL)                                                                                          \
        {                                                                                                              \
            printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());                                                  \
            SDL_DestroyWindow(window);                                                                                 \
            SDL_Quit();                                                                                                \
            return 1;                                                                                                  \
        }                                                                                                              \
    } while (false)

/// Clean up after a prior call to `HELPERS_INIT`.
///
/// `window` and `renderer` must exist in the current scope.
#define HELPERS_CLEANUP()                                                                                              \
    do                                                                                                                 \
    {                                                                                                                  \
        SDL_DestroyRenderer(renderer);                                                                                 \
        SDL_DestroyWindow(window);                                                                                     \
        SDL_Quit();                                                                                                    \
    } while (false)
