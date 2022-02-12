#ifndef HERO_HPP
#define HERO_HPP

#include "drawable.hpp"
#include "consts.hpp"

class Hero : public Drawable
{
    protected:
    Move_direction direction;
    hero_position position = hero_position::CENTER;
    SDL_Rect gSprites[3];
    int sprite_height[3];
    int sprite_width;
    int current_walking_step = 0;
    void loadMedia();
    bool init = true;
    bool is_out_of_border();
    bool walking_intro = true;
    plot_type bullet_start_pos;
    void set_bullet_start_pos();

    public:
    Hero(SDL_Renderer* r, const string& file_name);
    ~Hero();
    Move_direction& Direction() {return direction;}
    hero_position& Position() {return position;}
    void move_();
    void draw_();
    int Sprite_width() const {return sprite_width;}
    //Начальное полоежение выстрела
    plot_type& Bullet_start_position() {return bullet_start_pos;}
    bool Is_walking_intro() const {return walking_intro;}
    

};


#endif // {HERO_HPP}
