#include "star.hpp"

void Star::move_()
{
    if (kind == Star_kind::FAST_STAR)
    {
        upleftcorner.x -= FAST_STAR_SPEED;
    }
    else upleftcorner.x -= SLOW_STAR_SPEED;
    check_star_and_mainborder();
}

Star::Star() : Drawable()
{
    upleftcorner.x = getRandom(0, S_W);
    upleftcorner.y = getRandom(0, S_H);
    lt = nullptr;
    kind = Star_kind::SLOW_STAR;
}

Star::~Star()
{
    delete lt;
    lt = nullptr;
}

void Star::check_star_and_mainborder()
{
    if (upleftcorner.x < LEFT_BORDER)
    {
        upleftcorner.x = getRandom(S_W, S_W+300);
        upleftcorner.y = getRandom(0, S_H);
    }
}

void Star::draw_()
{
    lt->render(upleftcorner.x, upleftcorner.y);
}