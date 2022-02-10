#include "engine.hpp"

void draw(Drawable& object)
{
    object.draw_();
}

Starsky* init_sky(mySDL& mysdl, const string& file_name)
{
    Starsky* sky = new Starsky {mysdl.gRenderer, file_name};
    if (!sky->Init_status()) mysdl.all_init_ok = false;
    return sky;
}

void draw_sky(Starsky* sky)
{
    auto ptr_slow = &sky->Slow_stars()[0];
    auto ptr_fast = &sky->Fast_stars()[0];
    for (;;ptr_slow++, ptr_fast++)
    {
        if(ptr_slow == &sky->Slow_stars()[SLOW_STAR]) break;
        draw(*ptr_slow);
        draw(*ptr_fast);
    }
}

Backgrounds* init_backs(mySDL& mysdl)
{
    Backgrounds* backs = new Backgrounds {mysdl.gRenderer};
    if (!backs->Init_status()) mysdl.all_init_ok = false;
    return backs;
}

void draw_backs(Backgrounds* backs, GAME_HISTORY_NAMES history)
{
    auto ptr = &backs->All_back_fons()[static_cast<int>(history)];
    draw(*ptr);
}