#ifndef SDL_INIT_HPP
#define SDL_INIT_HPP


#include <iostream>
#include "consts.hpp"
#include "mysdl.hpp"




bool init(mySDL& sdl, const char* title);

void close(mySDL& sdl);

#endif
