#include "Decka.hpp"

static plot_type one_hero_lives_startpoint = {20, (S_H - DECKA_HEIGHT)+10};
static int one_hero_lives_shiftx = 10;

Decka::Decka(mySDL& mysdl, const string& file_name_decka, const string& file_name_onehero)
{
    decka_image = new Ltexture {mysdl.gRenderer, file_name_decka};
    if (!decka_image->get_Ltexture_status())
    {
        mysdl.all_init_ok = false;
        return;
    }
    deckaUpLeftCorner = {LEFT_BORDER, (S_H - DECKA_HEIGHT)};
    HeroLives = new Object_list<DeckTexture_listNode> {};
    if (!HeroLives)
    {
        std::cout << "\nCannot create list of hero lives, abort\n";
        mysdl.all_init_ok = false;
    }

    for (short count = 0; count < HERO_LIVES; count ++)
    {
        DeckTexture* one_hero_live = new DeckTexture {mysdl.gRenderer,file_name_onehero};
        if (!one_hero_live->get_Ltexture_status())
        {
            mysdl.all_init_ok = false;
            return;
        }
        one_hero_live->UpLeftCorner() = {one_hero_lives_startpoint.x + (count * (one_hero_live->get_mTexture_w() + one_hero_lives_shiftx) ),
                                        one_hero_lives_startpoint.y};
        HeroLives->Push_back(one_hero_live);
    }

}

Decka::~Decka()
{
    delete decka_image;
    decka_image = nullptr;
    delete HeroLives;
    HeroLives = nullptr;
}

//Отрисовка нижней деки
void Decka::draw_decka(const mySDL& mysdl)
{
    decka_image->render(deckaUpLeftCorner.x, deckaUpLeftCorner.y);
    //SDL_RenderPresent(mysdl.gRenderer);
}

//Отрисовка жизней героя в нижней деке
void Decka::draw_herolives(const mySDL& mysdl)
{
    draw_node(HeroLives->First());
    SDL_RenderPresent(mysdl.gRenderer);
}

