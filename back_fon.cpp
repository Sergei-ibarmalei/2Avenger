#include "back_fon.hpp"

Back_fon::Back_fon()
{
   upleftcorner = {0,0}; 
}

Back_fon::~Back_fon()
{
    delete lt;
    lt = nullptr;
}

void Back_fon::draw_()
{
    lt->render(upleftcorner.x, upleftcorner.y);
}