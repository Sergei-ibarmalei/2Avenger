#ifndef FL_HPP
#define FL_HPP

#include "object_list.hpp"
#include "al.hpp"
#include "consts.hpp"
#include "myrand.hpp"
#include "bez.hpp"

class Fl
{
    Object_list<Drawable_listNode> fleet;
    int count_of_fleet = 0;
    plot_type apperar_point;
    plot_type* reper_points = nullptr;
    plot_type* curve_way = nullptr;

    void make_curve(plot_type* rap, plot_type* way);
    


    public:
    Fl(SDL_Renderer* r, const string& fn, int count);
    ~Fl();
    void Draw();
    void Move(bool& time_to_cleanUP);
    //plot_type GetApPoint() {return apperar_point;}

};



#endif