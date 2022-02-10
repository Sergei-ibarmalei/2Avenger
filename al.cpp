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
    //length_curve_way = length;
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
    //std::cout << "\nIn Al start_curve_way: [" << start_curve_way.x << ',' << start_curve_way.y << "]\n";
}

void Al::move_()
{
    if (walking_intro)
    {
        upleftcorner = stright_way[current_walking_step++];
        if (current_walking_step == length_stright_way)
        {
            walking_intro = false;
            //std::cout << "\n[" << stright_way[length_stright_way-1].x << ',' << stright_way[length_stright_way-1].y << "] end of stright way";
            current_walking_step = 0;
        }
        return;
    }
    //std::cout << "\n[" << curve_way[0].x << ',' << curve_way[0].y << "] start of curve way";
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