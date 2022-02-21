#ifndef DECKA_HPP
#define DECKA_HPP

#include "Ltexture.hpp"
#include "object_list.hpp"
#include "mysdl.hpp"



class Decka
{
    Ltexture* decka_image = nullptr;
    plot_type deckaUpLeftCorner;

    

    public:

    Object_list<DeckTexture_listNode>* HeroLives = nullptr;
    Decka(mySDL& mysdl, const string& file_name_decka, const string& file_name_onehero);
    ~Decka();
    Decka(const Decka& ) {}
    void draw_decka();
    void draw_herolives(const mySDL& mysdl);



    
};




#endif