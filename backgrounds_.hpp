#ifndef BACKGROUNDS_HPP
#define BACKGROUNDS_HPP

#include "drawable.hpp"

class Backgrounds : public Drawable
{
    private:
    Ltexture* back_stages[3];
    GAME_HISTORY_NAMES history;

    public:
    Backgrounds(SDL_Renderer* r);
    ~Backgrounds();
    void move_();
    void draw_();
    GAME_HISTORY_NAMES& History() {return history;}
    Ltexture* Backs_arr() {return back_stages[0];}



};




#endif