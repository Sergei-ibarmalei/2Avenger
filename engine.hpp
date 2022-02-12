#ifndef ENGINE_HPP
#define ENGINE_HPP

//#include "drawable.hpp"
//#include "hero.hpp"
//#include "object_list.hpp"
#include "bullet.hpp"
#include "mysdl.hpp"
//#include "starsky.hpp"
//#include "backgrounds.hpp"
#include "consts.hpp"
//#include "fl.hpp"


#include "gametypes.hpp"






//Starsky* init_sky(mySDL& mysdl, const string& file_name);

//Backgrounds* init_backs(mySDL& mysdl);

//Hero* init_hero(mySDL& mysdl, const string& file_name);
void init_hero_type(hero_type& hero, mySDL& mysdl, const string& file_name);

void init_game_fon_type(game_fon_type& gft, mySDL& mysdl, const string& file_name);

void init_fleet_type(fleet_type& fleet, mySDL& mysdl, const string& file_name);

void init_game_item_type(game_item_type& status);

//Fl* init_fleet(mySDL& mysdl, const string& file_name, int count);

//Object_list<Drawable_listNode>* init_hero_bullet_list();
void init_bullet_list(mySDL& mysdl, bullet_type& bullets);

//void draw_sky(Starsky* sky);

//void draw_backs(Backgrounds* backs, GAME_HISTORY_NAMES history);
void draw_fon(game_fon_type& fon, const game_item_type& game);

//void close_hero_sky_backs(Hero* h, Starsky* s, Backgrounds* b);

void close_hero(hero_type& hero);

void close_fon(game_fon_type& fon);

//void close_fleet(Fl* f);

void close_fleet(fleet_type& fleet);

//void close_bullet_list(Object_list<Drawable_listNode>* l);

void close_bullet_list(bullet_type& bullet_list);

//void check_ship_move(mySDL& mysdl, SDL_Event& e, Hero* hero, Object_list<Drawable_listNode>* hero_bullet_list, bool& quit);
void check_ship_move(mySDL& mysdl, hero_type& hero, bullet_type& bullet_list, game_item_type& game);

#endif