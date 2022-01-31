#include "backgrounds.hpp"

Backgrounds::Backgrounds(SDL_Renderer* r) : Drawable()
{
    back_stages[0] = new Ltexture{r , "space_backs.png"};
    back_stages[1] = new Ltexture{r, "space_backs.png"};
    back_stages[2] = new Ltexture{r, "space_backs.png"};
    if (!back_stages[0]->get_Ltexture_status() || !back_stages[1]->get_Ltexture_status() 
        || !back_stages[2]->get_Ltexture_status()) init = false;
    upleftcorner = {0, 0};
    history = GAME_HISTORY_NAMES::FIRST;

}

Backgrounds::~Backgrounds()
{
    for (int i = 0; i < static_cast<int>(GAME_HISTORY_NAMES::ALL); i++)
    {
        delete back_stages[i];
        back_stages[i] = nullptr;
    }
}

void Backgrounds::move_() {}

void Backgrounds::draw_()
{
    back_stages[static_cast<int>(history)]->render(upleftcorner.x, upleftcorner.y);
}