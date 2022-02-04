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
    bool is_visible = true;
    //SDL_Renderer* render;
    //string name;

    public:
    Drawable(SDL_Renderer* r , const string& file_name = "");
    //Drawable(const Drawable& d);
    Drawable() {}
    virtual ~Drawable();
    plot_type& UpLeftCorner() {return upleftcorner;}
    virtual void move_() = 0;
    virtual void draw_() = 0;
    bool Init_status() const {return init;}
    bool Is_visible() {return is_visible;}
    //SDL_Renderer* Render() {return render;}
    //string Name ()  {return name;}

};




#endif