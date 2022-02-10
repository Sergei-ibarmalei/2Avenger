#ifndef FLEET_HPP
#define FLEET_HPP

#include "object_list.hpp"
#include "alien_small.hpp"
#include "consts.hpp"
#include "myrand.hpp"
#include "bez.hpp"

class Small_fleet
{
    Object_list<Drawable_listNode> fleet;
    int count_of_fleet = 0;
    plot_type reper_appear_point {0,0};
    plot_type* fleet_bezje_path = nullptr;
    plot_type* fleet_bezje_reper_pts = nullptr;
    void adding_ships(SDL_Renderer* r, const string& fn, int count);

    public:
    Small_fleet(SDL_Renderer* r, const string& fn,  int count);
    ~Small_fleet();
    void Fleet_move(bool& time_to_cleanup_fleet);
    void Fleet_draw();
    void CleanUP_from_invisible();

};



#endif