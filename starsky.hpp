#ifndef STARSKY_HPP
#define STARSKY_HPP

#include "star.hpp"

class Starsky
{
    private:
    Star* slow_stars = nullptr;
    Star* fast_stars = nullptr;
    bool init_status = true;

    public:
    Starsky(SDL_Renderer* r, const string& file_name);
    ~Starsky();
    void move();
    Star* Slow_stars()  {return &slow_stars[0];}
    Star*  Fast_stars()  {return &fast_stars[0];}
    bool Init_status() const {return init_status;}
};


#endif