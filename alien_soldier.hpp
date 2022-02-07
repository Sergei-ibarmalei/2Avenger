#ifndef ALIEN_SOLDIRER_HPP
#define ALIEN_SOLDIER_HPP

#include "drawable.hpp"
#include "alien_consts.hpp"
#include "bez.hpp"

class Alien_soldier: public Drawable
{
    plot_type* path = nullptr;
    size_t current_pos_index = 0;
    int curve_path_start_point = 0;
    int path_length = 0;
    

    public:
    Alien_soldier(SDL_Renderer* r, const string& file_name);
    ~Alien_soldier();
    void move_();
    void draw_();
    void set_path(plot_type* path_, const int length, const int curve_start_point);
};

Alien_soldier::Alien_soldier(SDL_Renderer* r, const string& file_name): Drawable(r, file_name)
{

}

void Alien_soldier::set_path(plot_type* bezje_path, const int length, const int curve_start_point)
{
    path = bezje_path;
    path_length = length;
    curve_path_start_point = curve_start_point;
}



Alien_soldier::~Alien_soldier()
{
    delete lt;
    lt = nullptr;
    //delete[] path;
    path = nullptr;
}

void Alien_soldier::move_()
{
    
    current_pos_index ++;
    if (current_pos_index == path_length)
    {
        current_pos_index = curve_path_start_point;
    }
    upleftcorner = path[current_pos_index];
}

void Alien_soldier::draw_()
{
    lt->render(upleftcorner.x, upleftcorner.y);
}





#endif