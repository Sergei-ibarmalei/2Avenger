#include "sdl_init.hpp"

bool init(mySDL& sdl, const char* title)
{

    if(SDL_Init( SDL_INIT_VIDEO ) < 0)
    {
        std::cout << "Невозможно инициализировать SDL. Ошибка " << SDL_GetError() << '\n';
        return false;
    }

    if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    {
        std::cout << "Не подключена опция linear texture filtering." ;
        return false;
    }

    sdl.gWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, S_W, S_H, SDL_WINDOW_SHOWN);
    if(!sdl.gWindow)
    {
        std::cout << "Невозможно инициализировать окно window, ошибка " << SDL_GetError() << '\n';
        return false;
    }
    sdl.gRenderer = SDL_CreateRenderer(sdl.gWindow, -1, SDL_RENDERER_SOFTWARE /*SDL_RENDERER_ACCELERATED*/);
    if(!sdl.gRenderer)
    {
        std::cout << "Невозможно инициализировать параметр Renderer, ошибка " << SDL_GetError() << '\n';
        return false;
    }

    int imgFlags = IMG_INIT_JPG;
    if(!(IMG_Init(imgFlags) & imgFlags))
    {
        std::cout << "Невозможно инициализировать SDL_image, ошибка " << IMG_GetError() << '\n';
        return false;
    }

    if( TTF_Init() == -1)
    {
        std::cout << "Невозможно инициализировать SDL_ttf, ошибка." << TTF_GetError() << '\n';
        return false;
    }
    return true;


}

void close(mySDL& sdl)
{
    SDL_DestroyRenderer(sdl.gRenderer);
    SDL_DestroyWindow(sdl.gWindow);
    sdl.gRenderer= nullptr;
    sdl.gWindow= nullptr;
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
