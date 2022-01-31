#ifndef BULLET_HPP
#define BULLET_HPP


#include "drawable.hpp"

class Bullet : public Drawable
{
    protected:
    Bullet_direction bullet_direction;
    bool is_bullet_out_of_border();
    bool is_visible = true;

    public:
    Bullet(SDL_Renderer* r, const string& file_name, Bullet_direction dir = Bullet_direction::NONE);
    ~Bullet();
    void move_();
    void draw_();
    Bullet_direction& Direction() {return bullet_direction;}
    

};

#endif