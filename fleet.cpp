#include "fleet.hpp"

Small_fleet::~Small_fleet()
{
    delete[] fleet_bezje_reper_pts;
    fleet_bezje_reper_pts = nullptr;
    delete[] fleet_bezje_path;
    fleet_bezje_path = nullptr;
}

Small_fleet::Small_fleet(SDL_Renderer* r, const string& fn,  int count)
{
    count_of_fleet = count;
    //reper_appear_point.x = S_W - ALIEN_SHIFT_X;
    //reper_appear_point.y = getRandom(200, S_H-50);
    reper_appear_point.x = S_W-60;
    reper_appear_point.y = S_H/2;
    fleet_bezje_reper_pts = new plot_type[4];
    fleet_bezje_reper_pts = set_reper_points(reper_appear_point);
    fleet_bezje_path = new plot_type[ALIEN_BEZJE_PATH];
    make_path_bezje(fleet_bezje_path, fleet_bezje_reper_pts);
    adding_ships(r, fn, count);

}

void Small_fleet::adding_ships(SDL_Renderer* r, const string& fn, int count)
{
    for (int i = 0; i < count; i++)
    {
        Alien_small* ship = new Alien_small {r, fn,reper_appear_point, count};
        ship->SetBezjePath(fleet_bezje_path);
        fleet.Push_back(ship);
    }
}

void Small_fleet::Fleet_move(bool& time_to_cleanup_fleet)
{

   move_node(fleet.First(), time_to_cleanup_fleet); 
}

void Small_fleet::CleanUP_from_invisible()
{
    fleet.CleanUP_from_invisible();
}

void Small_fleet::Fleet_draw()
{
    draw_node(fleet.First());
}