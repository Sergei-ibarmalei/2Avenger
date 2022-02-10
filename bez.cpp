#include "bez.hpp"
#include <iostream>

plot_type* set_reper_points(const plot_type& start_p)
{
    plot_type* reper_points = new plot_type[4];
    reper_points[0] = start_p;

    reper_points[1].x = reper_points[0].x - ALIEN_BEZJE_PATH / 8;
    reper_points[1].y = reper_points[0].y - ALIEN_BEZJE_HEIGHT;

    reper_points[2].x = reper_points[0].x - 3 * (ALIEN_BEZJE_PATH / 8);
    reper_points[2].y = reper_points[0].y + ALIEN_BEZJE_HEIGHT;

    reper_points[3].x = reper_points[0].x - ALIEN_BEZJE_PATH / 2;
    reper_points[3].y = reper_points[0].y;

    return reper_points;
}

void make_path_bezje(plot_type* path_, plot_type* reper_points)
{
    double t_bezje {0.0};
    auto ptr = &path_[0];
    int half_path {ALIEN_BEZJE_PATH /2 };
    for(;;ptr++)
    {
        if(ptr == &path_[half_path]) break;
        ptr->x = get_t(3, t_bezje) * reper_points[0].x + 
                3 *  t_bezje * (get_t(2, t_bezje)) * reper_points[1].x + 
                3 * t_bezje * t_bezje * (1 - t_bezje) * reper_points[2].x + 
                t_bezje * t_bezje * t_bezje * reper_points[3].x;
        ptr->y = get_t(3, t_bezje) * reper_points[0].y + 
                3 * t_bezje * (get_t(2, t_bezje)) * reper_points[1].y +
                3 * t_bezje * t_bezje * (1 - t_bezje) * reper_points[2].y +
                t_bezje * t_bezje * t_bezje * reper_points[3].y;
        //std::cout << "\n[" << ptr->x << ',' << ptr->y << "]";
        t_bezje += (1.0 / half_path);
    }
    t_bezje = 0.0;
    ptr = &path_[half_path];
    for(;;ptr++)
    {
        if(ptr == &path_[ALIEN_BEZJE_PATH]) break;
        ptr->x = get_t(3, t_bezje) * reper_points[3].x +
                3 * t_bezje * (get_t(2, t_bezje)) * reper_points[2].x + 
                3 * t_bezje * t_bezje * (1 - t_bezje) * reper_points[1].x +
                t_bezje * t_bezje * t_bezje * reper_points[0].x;
        ptr->y = get_t(3, t_bezje) * reper_points[3].y +
                3 * t_bezje * (get_t(2, t_bezje)) * reper_points[1].y +
                3 * t_bezje * t_bezje * (1 - t_bezje) * reper_points[2].y +
                t_bezje * t_bezje * t_bezje * reper_points[3].y;
        //std::cout << "\n[" << ptr->x << ',' << ptr->y << "]";
        t_bezje += (1.0 / half_path);
    }


}

double get_t(int power, const double t_bezje)
{
    if (power == 0) return 1;
    else 
    {
        power -= 1;
        return (1 - t_bezje) * (get_t(power, t_bezje));
    }
}