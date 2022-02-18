#ifndef GAMETYPES_HPP
#define GAMETYPES_HPP

#include "hero.hpp"
#include "starsky.hpp"
#include "backgrounds.hpp"
#include "object_list.hpp"
#include "Decka.hpp"
#include "fl.hpp"

//enum class GAME_HISTORY_PART {FIRST, SECOND, ALL};

typedef struct
{
    Hero* hero = nullptr;
    //bool Is_walking_intro = true;

}hero_type;

typedef struct
{
    Starsky* sky       = nullptr;
    Backgrounds* backs = nullptr;
}game_fon_type;


typedef struct
{
    Object_list<Drawable_listNode>* HeroBulletList = nullptr;
    bool time_to_cleanup_bhl = false;

}bullet_type;

typedef struct
{
    Fl* three_alien_fighter = nullptr;
    bool time_to_cleanup_fleet = false;

}fleet_type;

typedef struct 
{
    GAME_HISTORY_PART game_part;
    bool game_quit   = false;
    bool game_paused = false;
    unsigned short hero_lives = HERO_LIVES;

}game_item_type;

typedef struct
{
    Ltexture* pause = nullptr;
}text_type;



typedef struct
{
    Ltexture* text_pause = nullptr;
    const string decka_image = "deck_1.png";
    const string decka_onehero = "onehero.png";
    const string string_pause  = "PAUSE";
    Decka* deck;
}game_gui_type;




#endif