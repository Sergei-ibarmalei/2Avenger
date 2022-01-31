#include "backgrounds.hpp"

Backgrounds::Backgrounds(SDL_Renderer* r)
{
    Ltexture* first = new Ltexture {r, "first_background.png"};
    if (!first->get_Ltexture_status()) init = false;
    all_back_fons[0] = new Back_fon();
    all_back_fons[0]->Set_Ltexture(first);

    Ltexture* second = new Ltexture {r, "first_background.png"};
    if (!first->get_Ltexture_status()) init = false;
    all_back_fons[1] = new Back_fon();
    all_back_fons[1]->Set_Ltexture(second);

    Ltexture* third = new Ltexture {r, "first_background.png"};
    if (!first->get_Ltexture_status()) init = false;
    all_back_fons[2] = new Back_fon();
    all_back_fons[2]->Set_Ltexture(third);


}

Backgrounds::~Backgrounds()
{
    for(int i = 0; i < static_cast<int>(GAME_HISTORY_NAMES::ALL); i++)
    {
        delete all_back_fons[i];
        all_back_fons[i] = nullptr;
    }
}