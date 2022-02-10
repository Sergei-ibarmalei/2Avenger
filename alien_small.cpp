#include "alien_small.hpp"

Alien_small::Alien_small(SDL_Renderer* r, const string& fn,const plot_type& rap, int nomber_in_row) : Drawable(r, fn)
{
    intro_path_length = ALIEN_INTRO_PATH + (ALIEN_SHIFT_X* nomber_in_row);
    intro_path = new plot_type[intro_path_length];
    upleftcorner.x = rap.x + (ALIEN_SHIFT_X * nomber_in_row);
    upleftcorner.y = rap.y;
    make_intro_path();


}



void Alien_small::move_()
{
    if (walking_by_intro)
    {
        upleftcorner = intro_path[current_walking_index];
        current_walking_index ++;
        if (current_walking_index == intro_path_length)
        {
            walking_by_intro = false;
            //walking_by_curve = true;
            current_walking_index = 0;
        }
        return;
    }
    upleftcorner = bezje_path[current_walking_index];
    current_walking_index ++;
    if (current_walking_index == /*bezje_path_length*/ ALIEN_BEZJE_PATH)
    {
        current_walking_index = 0;
    }

}

void Alien_small::draw_()
{
    lt -> render(upleftcorner.x, upleftcorner.y);
}

Alien_small::~Alien_small()
{
    delete[] intro_path;
    intro_path = nullptr;
    delete lt;
    lt = nullptr;
}

void Alien_small::SetBezjePath(plot_type* bp/*, const int length*/)
{
    bezje_path = bp;
    //bezje_path_length = length;
}




void Alien_small::make_intro_path()
{
    intro_path[0] = upleftcorner;
    auto ptr = &intro_path[1];
    int count = 1;
    for(;;ptr++, count++)
    {
        if (ptr == &intro_path[intro_path_length]) break;
        ptr->x = intro_path[0].x - count;
        ptr->y = intro_path[0].y;
    }
}