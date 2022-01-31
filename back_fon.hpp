#ifndef BACK_FON_HPP
#define BACK_FON_HPP
#include "drawable.hpp"


class Back_fon : public Drawable
{
    //string file_name = "";

    public:
    Back_fon();
    ~Back_fon();
    void move_() {}
    void draw_();
    //string& File_name() {return file_name;}
    void Set_Ltexture(Ltexture* lt_) {lt = lt_;}

    
};




#endif