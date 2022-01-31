#ifndef SDL_INIT_HPP
#define SDL_INIT_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "consts.hpp"

typedef struct 
{
    SDL_Window* gWindow = nullptr;
    SDL_Renderer* gRenderer = nullptr;
}mySDL;


bool init(mySDL& sdl, const char* title);

void close(mySDL& sdl);

#endif
