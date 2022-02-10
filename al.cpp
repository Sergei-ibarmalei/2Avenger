#include "al.hpp"

Al::Al(SDL_Renderer* r, const string& fn, const plot_type& ap, int count_in_raw_): Drawable(r, fn)
{
    count_in_raw = count_in_raw_;
    appear_point = ap;
    make_stright_way();

}

void Al::SetCurvePath(plot_type* curve)
{
    curve_way = curve;
}

Al::~Al()
{
    delete[] stright_way;
    stright_way = nullptr;
}

void Al::make_stright_way()
{
    int intro_ = ALIEN_INTRO_PATH + (ALIEN_SHIFT_X * count_in_raw);
    upleftcorner.x = appear_point.x + (ALIEN_SHIFT_X * count_in_raw);
    upleftcorner.y = appear_point.y;
    length_stright_way = intro_;

    stright_way = new plot_type[length_stright_way];
    stright_way[0] = upleftcorner;
    int count = 1;
    auto ptr = &stright_way[1];
    for (;;ptr++, count++)
    {
        if (ptr == &stright_way[length_stright_way]) break;
        ptr->x = stright_way[0].x - count;
        ptr->y = stright_way[0].y;
    }

    start_curve_way = stright_way[length_stright_way - 1 ];
}

void Al::move_()
{
    if (walking_intro)
    {
        upleftcorner = stright_way[current_walking_step++];
        if (current_walking_step == length_stright_way)
        {
            walking_intro = false;
            current_walking_step = 0;
        }
        return;
    }
    upleftcorner = curve_way[current_walking_step++];
    if (current_walking_step == ALIEN_BEZJE_PATH)
    {
        current_walking_step = 0;
    }
}

void Al::draw_()
{
    lt->render(upleftcorner.x, upleftcorner.y);
}