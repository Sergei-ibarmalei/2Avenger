#ifndef STAR_HPP
#define STAR_HPP

#include "drawable.hpp"
#include "consts.hpp"
#include "myrand.hpp"

class Star : public Drawable
{
    private:
    void check_star_and_mainborder();
    Star_kind kind;



    public:
    Star();
    ~Star();
    Star_kind& Kind() {return kind;}
    void move_();
    void draw_();
    void SetLtexture(Ltexture* lt_) {lt = lt_;}

};





#endif