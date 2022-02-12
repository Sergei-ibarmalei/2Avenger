#ifndef BACKGROUNDS_HPP
#define BACKGROUNDS_HPP


#include "back_fon.hpp"
#include "consts.hpp"

class Backgrounds
{
    private:
    Back_fon* all_back_fons = nullptr;
    bool init = true;
    
    public:
    Backgrounds(SDL_Renderer* r);
    ~Backgrounds();
    Back_fon* All_back_fons() {return &all_back_fons[0];}
    bool Init_status() const {return init;}



};



#endif