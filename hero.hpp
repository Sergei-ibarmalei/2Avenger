#ifndef HERO_HPP
#define HERO_HPP

#include "drawable.hpp"
#include "consts.hpp"

class Hero : public Drawable
{
    protected:
    Move_direction direction;
    hero_position position;
    SDL_Rect gSprites[3];
    int sprite_height[3];
    int sprite_width;
    void loadMedia();
    bool init = true;
    bool is_out_of_border();

    public:
    Hero(SDL_Renderer* r, const string& file_name);
    ~Hero();
    Move_direction& Direction() {return direction;}
    hero_position& Position() {return position;}
    void move_();
    void draw_();

};


#endif // {HERO_HPP}
