#ifndef BACK_FON_HPP
#define BACK_FON_HPP
#include "drawable.hpp"


class Back_fon : public Drawable
{

    public:
    Back_fon();
    ~Back_fon();
    void move_() {}
    void draw_();
    void Set_Ltexture(Ltexture* lt_) {lt = lt_;}

    
};




#endif