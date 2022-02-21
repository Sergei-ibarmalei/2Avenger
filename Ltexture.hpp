#ifndef LTEXTURE_HPP
#define LTEXTURE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "consts.hpp"
#include <iostream>
#include <string>

using std::string;

enum class Kind_of_texture {IMAGE, TEXT, NONE};

//Класс текстуры
class Ltexture
{
    protected:

    Kind_of_texture kind = Kind_of_texture::NONE;
    bool Ltexture_init = true;
    SDL_Texture* mTexture;
    SDL_Renderer* renderer;
    TTF_Font* gFont = nullptr;
    SDL_Color color;
    int mTexture_w;
    int mTexture_h;
    //Загрузка медиа для текста
    void free();


    public:
    //Конструктор для графики
    Ltexture(SDL_Renderer* renderer_, const string& name);
    //Конструктор для текста
    Ltexture(SDL_Renderer* renderer_, const string& text, int textSize, const SDL_Color& textColor);
    Ltexture(const Ltexture& ) {}
    Ltexture();
    ~Ltexture();

    void loadFromFile(const string& name);
    void loadMediaText(int textSize);

    SDL_Texture* get_texture() const {return mTexture;}
    int get_mTexture_w() const {return mTexture_w;}
    int get_mTexture_h() const {return mTexture_h;}
    bool get_Ltexture_status() const {return Ltexture_init;}
    void render(int x, int y, SDL_Rect* clip = nullptr);
    Kind_of_texture& getKind() {return kind;}
    SDL_Color& Color() {return color;}
    //SDL_Color& TextColor() {return color;}
    
    
};


//Класс для отрисовки текстуры жизней в деке
 class DeckTexture: public Ltexture
{
    private:
    bool is_visible = true;
    plot_type upleftcorner;

    public:
    DeckTexture();
    DeckTexture(SDL_Renderer* renderer_, const string& file_name);
    ~DeckTexture();
    void SetRenderer(SDL_Renderer* r) {renderer = r;}
    TTF_Font* getFont() const {return gFont;}
    bool& Is_visible() {return is_visible;}
    plot_type& UpLeftCorner() {return upleftcorner;}
    void draw_();

}; 



#endif
