#ifndef ALIEN_SMALL_HPP
#define ALIEN_SMALL_HPP


#include "alien_consts.hpp"
#include "drawable.hpp"
//#include "myrand.hpp"

class Alien_small : public Drawable
{

    protected:
    plot_type* intro_path = nullptr;
    plot_type* bezje_path = nullptr;
    //Реперная точка появления
    plot_type reper_appear_point;

    bool walking_by_intro = true;
    //bool walking_by_curve = false;

    int current_walking_index = 0;
    int intro_path_length = 0;
    //int bezje_path_length = 0;
    
    void make_intro_path();



    public:
    Alien_small(SDL_Renderer* r, const string& file_name,const plot_type& rap, int nomber_in_row);
    ~Alien_small();
    void SetBezjePath(plot_type* bp/*, const int length*/);
    void move_();
    void draw_();
};




#endif