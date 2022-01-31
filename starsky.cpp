#include "starsky.hpp"


Starsky::Starsky(SDL_Renderer* r, const string& file_name)
{
    slow_stars = new Star[SLOW_STAR];
    fast_stars = new Star[FAST_STAR];

    auto ptr_slow = &slow_stars[0];
    auto ptr_fast = &fast_stars[0];
    for(;;ptr_slow++, ptr_fast++)
    {
        if(ptr_slow == &slow_stars[SLOW_STAR]) break;
        Ltexture* lt_slow = new Ltexture {r, file_name};
        if (!lt_slow->get_Ltexture_status())
        {
            init_status = false;
            return;
        }
        ptr_slow->SetLtexture(lt_slow);
        ptr_slow->Kind() = Star_kind::SLOW_STAR;

        Ltexture* lt_fast = new Ltexture {r, file_name};
        if (!lt_fast->get_Ltexture_status())
        {
            init_status = false;
            return;
        }
        ptr_fast->SetLtexture(lt_fast);
        ptr_fast->Kind() = Star_kind::FAST_STAR;
    }
}

Starsky::~Starsky()
{
    if (slow_stars) delete[] slow_stars;
    if (fast_stars) delete[] fast_stars;
}


void Starsky::move()
{
    auto ptr_slow = &slow_stars[0];
    auto ptr_fast = &fast_stars[0];
    for(;;ptr_slow++, ptr_fast++)
    {
        if (ptr_slow == &slow_stars[SLOW_STAR]) break;
        ptr_slow->move_();
        ptr_fast->move_();
    }
}