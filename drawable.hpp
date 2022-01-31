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
    plot_type upleftcorner;
    bool init = true;

    public:
    Drawable(SDL_Renderer* r , const string& file_name = "");
    Drawable() {}
    ~Drawable() {}
    plot_type& UpLeftCorner() {return upleftcorner;}
    virtual void move_() = 0;
    virtual void draw_() = 0;
    bool Init_status() const {return init;}

};




#endif