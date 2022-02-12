#include "backgrounds.hpp"

Backgrounds::Backgrounds(SDL_Renderer* r)
{
    all_back_fons = new Back_fon[static_cast<int>(GAME_HISTORY_PART::ALL)];
    Ltexture* first = new Ltexture {r, "first_background.png"};
    if (!first->get_Ltexture_status()) init = false;
    all_back_fons[0].Set_Ltexture(first);

    Ltexture* second = new Ltexture {r, "first_background.png"};
    if (!first->get_Ltexture_status()) init = false;
    all_back_fons[1].Set_Ltexture(second);

    Ltexture* third = new Ltexture {r, "first_background.png"};
    if (!first->get_Ltexture_status()) init = false;
    all_back_fons[2].Set_Ltexture(third);


}

Backgrounds::~Backgrounds()
{
    delete[] all_back_fons;
    all_back_fons = nullptr;
}