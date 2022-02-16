#include "Ltexture.hpp"

Ltexture::Ltexture(SDL_Renderer* renderer_, const string& name): renderer(renderer_)
//Конструктор для графики
{
    kind = Kind_of_texture::IMAGE;
    mTexture = nullptr;
    mTexture_w = mTexture_h = 0;
    loadFromFile(name);
}


Ltexture::Ltexture(SDL_Renderer* renderer_, const string& text, int textSize, const SDL_Color& textcolor):renderer(renderer_)
//Конструктор для текста
{
    kind = Kind_of_texture::TEXT;
    mTexture = nullptr;
    mTexture_w = mTexture_h = 0;
    color = textcolor;
    loadMediaText(textSize);
    if (gFont)
        loadFromFile(text);
    

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
    /* if (gFont)
    {
        TTF_CloseFont(gFont);
        gFont = nullptr;
    } */
}

void Ltexture::loadMediaText(int textSize)
{
    
    if ( (textSize < 10) || (textSize > 100))
    {
        std::cout << "\nTextsize error, abort.\n";
        Ltexture_init = false;
        return;
    }
    gFont = TTF_OpenFont("sfns-display-bold.ttf", textSize);
    if (gFont == nullptr)
    {
        std::cout << "Failed to load font, SDL_ttf error: " << TTF_GetError() << '\n';
        Ltexture_init = false;
    }
}

void Ltexture::loadFromFile(const string& string)
{
    free();
    SDL_Texture* newTexture = nullptr;

    switch (kind)
    {
        case Kind_of_texture::IMAGE:
        {
            SDL_Surface* loadedSurface = IMG_Load(string.c_str());
            if(!loadedSurface)
            {
                std::cout << "Unable to load image " << string << " SDL_image error: " <<
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
                    std::cout << "Unable to create texture from " << string << " SDL Error: " <<
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
            break;
        }
        case Kind_of_texture::TEXT:
        {
            SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, string.c_str(), color);
            if (!textSurface)
            {
                std::cout << "Unable to render text surface, SDL_ttf error: " << TTF_GetError() << '\n';
                Ltexture_init = false;
                return;
            }
            else
            {
                newTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                if (!newTexture)
                {
                    std::cout << "Unable to create texture from text, error: " << SDL_GetError() << '\n';
                    Ltexture_init = false;
                    return;
                }
                else
                {
                    mTexture_w = textSurface->w;
                    mTexture_h= textSurface->h;
                }
                SDL_FreeSurface(textSurface);
            }
            break;
        }
        default: {}

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


DeckTexture::DeckTexture(SDL_Renderer* renderer_, const string& file_name) : Ltexture(renderer_, file_name)
{

}

DeckTexture::~DeckTexture()
{
    free();
}
