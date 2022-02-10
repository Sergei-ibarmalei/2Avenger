#ifndef AL_HPP
#define AL_HPP

#include "alien_consts.hpp"
#include "drawable.hpp"



class Al : public Drawable
{
    protected:
    plot_type* stright_way = nullptr;
    plot_type* curve_way = nullptr;
    int length_stright_way;
    //int length_curve_way;
    int count_in_raw;
    int current_walking_step = 0;
    plot_type start_stright_way;
    plot_type start_curve_way;
    plot_type appear_point;
    bool walking_intro = true;


    void make_stright_way();

    public:
    Al(SDL_Renderer* r, const string& fn, const plot_type& ap, int count_in_raw_);
    ~Al();
    void move_();
    void draw_();
    void SetCurvePath(plot_type* curve);
};



#endif