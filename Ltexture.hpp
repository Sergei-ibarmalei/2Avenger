#ifndef LTEXTURE_HPP
#define LTEXTURE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

using std::string;

enum class Kind_of_texture {IMAGE, TEXT, NONE};

class Ltexture
{
    Kind_of_texture kind = Kind_of_texture::NONE;
    bool Ltexture_init = true;
    SDL_Texture* mTexture;
    SDL_Renderer* renderer;
    TTF_Font* gFont = nullptr;
    SDL_Color color;
    int mTexture_w;
    int mTexture_h;
    void loadFromFile(const string& name);
    //Загрузка медиа для текста
    void loadMediaText(int textSize);
    void free();


    public:
    //Конструктор для графики
    Ltexture(SDL_Renderer* renderer_, const string& name);
    //Конструктор для текста
    Ltexture(SDL_Renderer* renderer_, const string& text, int textSize, SDL_Color& textcolor);
    ~Ltexture();
    SDL_Texture* get_texture() const {return mTexture;}
    int get_mTexture_w() const {return mTexture_w;}
    int get_mTexture_h() const {return mTexture_h;}
    bool get_Ltexture_status() const {return Ltexture_init;}
    void render(int x, int y, SDL_Rect* clip = nullptr);
    SDL_Color& TextColor() {return color;}
    
    
};

#endif
