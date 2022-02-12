#ifndef MYSDL_HPP
#define MYSDL_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
typedef struct 
{
    SDL_Window* gWindow = nullptr;
    SDL_Renderer* gRenderer = nullptr;
    bool all_init_ok = true;
    SDL_Event e;
}mySDL;

#endif