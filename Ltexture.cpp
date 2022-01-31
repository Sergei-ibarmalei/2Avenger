#include "Ltexture.hpp"

Ltexture::Ltexture(SDL_Renderer* renderer_, const string& name): renderer(renderer_)
{
    mTexture = nullptr;
    mTexture_w = mTexture_h = 0;
    loadFromFile(name);
}

Ltexture::~Ltexture()
{
    free();
}

void Ltexture::free()
{
    if(mTexture)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        mTexture_w = mTexture_h = 0;
    }
}

void Ltexture::loadFromFile(const string& name)
{
    free();
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(name.c_str());
    if(!loadedSurface)
    {
        std::cout << "Unable to load image " << name << " SDL_image error: " <<
            IMG_GetError() << '\n';
        Ltexture_init = false;
        return;
    }
    else
    {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(!newTexture)
        {
            std::cout << "Unable to create texture from " << name << " SDL Error: " <<
                SDL_GetError() << '\n';
            Ltexture_init = false;
            return;
        }
        else
        {
            mTexture_w = loadedSurface->w;
            mTexture_h = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
    }
    mTexture = newTexture;
}

void Ltexture::render(int x, int y, SDL_Rect* clip)
{
    SDL_Rect renderQuad = {x, y, mTexture_w, mTexture_h};
    if(clip)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopy(renderer, mTexture, clip, &renderQuad);
}
