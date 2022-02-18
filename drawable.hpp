#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "Ltexture.hpp"
#include "consts.hpp"
#include <string>

using std::string;

class Drawable
{
    protected:
    Ltexture* lt = nullptr;
    //Прямой путь в начале
    plot_type* stright_way = nullptr;
    plot_type upleftcorner;
    int length_stright_way = 0;
    bool init = true;
    bool is_visible = true;

    public:
    Drawable(SDL_Renderer* r , const string& file_name = "");
    Drawable() {}
    virtual ~Drawable();
    plot_type& UpLeftCorner() {return upleftcorner;}
    virtual void move_() = 0;
    virtual void draw_() = 0;
    bool Init_status() const {return init;}
    bool Is_visible() {return is_visible;}

};

void draw(Drawable& object);
void draw(DeckTexture& object);
//template<class T>
//void draw(T& object);

plot_type* making_stright(const plot_type& upleftcorner, int length, Move_direction direction);

void Walking_intro(plot_type& corner, plot_type* way, int& step, int length, bool& walking);




#endif