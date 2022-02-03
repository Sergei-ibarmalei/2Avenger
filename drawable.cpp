#include "drawable.hpp"

Drawable::Drawable(SDL_Renderer* r, const string& file_name)
{
    lt = new Ltexture(r, file_name);
    if(!lt->get_Ltexture_status())
    {
        init = false;
    }
    //render = r;
    //name = file_name;
}

/* Drawable::Drawable(const Drawable& d)
{
    lt = new Ltexture(render, name);
    if (!lt->get_Ltexture_status()) init = false;
    upleftcorner = d.upleftcorner;
    init = d.init;
} */

Drawable::~Drawable()
{
    //delete lt;
    //lt = nullptr;
}