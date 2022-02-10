#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "drawable.hpp"
#include "hero.hpp"
#include "object_list.hpp"
#include "bullet.hpp"
#include "mysdl.hpp"
#include "starsky.hpp"
#include "backgrounds.hpp"
#include "consts.hpp"
#include "fl.hpp"




//void draw(Drawable& object);


Starsky* init_sky(mySDL& mysdl, const string& file_name);

Backgrounds* init_backs(mySDL& mysdl);

Hero* init_hero(mySDL& mysdl, const string& file_name);

Fl* init_fleet(mySDL& mysdl, const string& file_name, int count);

void draw_sky(Starsky* sky);

void draw_backs(Backgrounds* backs, GAME_HISTORY_NAMES history);

void close_hero_sky_backs(Hero* h, Starsky* s, Backgrounds* b);

void close_fleet(Fl* f);

void check_ship_move(mySDL& mysdl, SDL_Event& e, Hero* hero, Object_list<Drawable_listNode>& hero_bullet_list, bool& quit);

#endif