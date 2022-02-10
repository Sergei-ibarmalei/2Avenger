#include "fl.hpp"

Fl::~Fl()
{
    delete[] reper_points;
    reper_points = nullptr;
    delete[] curve_way;
    curve_way = nullptr;
}

Fl::Fl(SDL_Renderer* r, const string& fn, int count)
{
    count_of_fleet = count;
    apperar_point.x = S_W - 60;
    apperar_point.y = S_H / 2;
    plot_type start_curv {apperar_point.x - 100, apperar_point.y};
    curve_way = new plot_type[ALIEN_BEZJE_PATH];
    reper_points = set_reper_points(start_curv);
    make_path_bezje(curve_way, reper_points);
    for (int i = 0; i < count; i++)
    {
        Al* alien = new Al {r, fn, apperar_point, i};
        alien->SetCurvePath(curve_way);
        fleet.Push_back(alien);
    }

}

void Fl::Draw()
{
    draw_node(fleet.First());
}

void Fl::Move(bool& time_to_cleanUP)
{
    move_node(fleet.First(), time_to_cleanUP);
}