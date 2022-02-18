#include "drawable.hpp"

Drawable::Drawable(SDL_Renderer* r, const string& file_name)
{
    lt = new Ltexture(r, file_name);
    if(!lt->get_Ltexture_status())
    {
        init = false;
    }
}


Drawable::~Drawable()
{
}

//Отрисовка объекта Drawable
void draw(Drawable& object)
//template<class T>
//void draw(T& object)
{
    object.draw_();
}

void draw(DeckTexture& object)
{
    object.draw_();
}

plot_type* making_stright(const plot_type& upleftcorner, int length, Move_direction direction)
{
    if (length <= 0)  return nullptr;
    plot_type* stright_way = new plot_type[length];
    stright_way[0] = upleftcorner;
    int count = 1;
    auto ptr = &stright_way[1];
    for (;;ptr++, count++)
    {
        if (ptr == &stright_way[length]) break;
        if (direction == Move_direction::LEFT)
            ptr->x = stright_way[0].x - count;
        if (direction == Move_direction::RIGHT)
            ptr->x = stright_way[0].x + count;
        ptr->y = stright_way[0].y;
    }
    return stright_way;
}

void Walking_intro(plot_type& corner, plot_type* way, int& step, int length, bool& walking)
{
    corner = way[step++];
    if (step == length)
    {
        walking = false;
        step = 0;
    }
}