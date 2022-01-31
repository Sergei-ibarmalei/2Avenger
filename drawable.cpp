#include "drawable.hpp"

Drawable::Drawable(SDL_Renderer* r, const string& file_name)
{
    lt = new Ltexture(r, file_name);
    if(!lt->get_Ltexture_status())
    {
        init = false;
    }
}