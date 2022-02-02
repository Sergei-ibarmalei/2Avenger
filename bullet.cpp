#include "bullet.hpp"

Bullet::Bullet(SDL_Renderer* r, const string& file_name, const plot_type& start_pos, Bullet_direction dir) : Drawable(r, file_name)
{
    upleftcorner = start_pos;
    bullet_direction = dir;
}

Bullet::~Bullet()
{
    delete lt;
    lt = nullptr;
}

bool Bullet::is_bullet_out_of_border()
{
    switch (bullet_direction)
    {
        case Bullet_direction::LEFT:
            return upleftcorner.x < LEFT_BORDER;
            break;
        case Bullet_direction::RIGHT:
            return upleftcorner.x > RIGHT_BORDER;
            break;
        case Bullet_direction::COMPLEX:
        case Bullet_direction::NONE:
        default: {}

        
    }
    return false;
}

void Bullet::move_()
{
    if (!is_visible) return;
    switch (bullet_direction)
    {
        case Bullet_direction::LEFT:
            upleftcorner.x -= BULLET_SPEED;
            break;
        case Bullet_direction::RIGHT:
            upleftcorner.x += BULLET_SPEED;
            break;
        case Bullet_direction::NONE:
        case Bullet_direction::COMPLEX:
        default: {}
    }
    if (is_bullet_out_of_border()) is_visible = false;
}

void Bullet::draw_()
{
    lt->render(upleftcorner.x, upleftcorner.y);
}


Bullet::Bullet(const Bullet& b) : Drawable(b)
{
    bullet_direction = b.bullet_direction;
}

