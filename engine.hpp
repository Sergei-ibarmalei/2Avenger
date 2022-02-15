#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "bullet.hpp"
#include "mysdl.hpp"
#include "consts.hpp"


#include "gametypes.hpp"



void init_hero_type(hero_type& hero, mySDL& mysdl, const string& file_name);

void init_game_fon_type(game_fon_type& gft, mySDL& mysdl, const string& file_name);

void init_fleet_type(fleet_type& fleet, mySDL& mysdl, const string& file_name);

void init_game_item_type(game_item_type& status);


void init_bullet_list(mySDL& mysdl, bullet_type& bullets);


void draw_fon(game_fon_type& fon, const game_item_type& game);


void close_hero(hero_type& hero);

void close_fon(game_fon_type& fon);


void close_fleet(fleet_type& fleet);


void close_bullet_list(bullet_type& bullet_list);

void check_ship_move(mySDL& mysdl, hero_type& hero, bullet_type& bullet_list, game_item_type& game);

void Hero_walking_intro(mySDL& mysdl, hero_type& hero, game_fon_type& fon, game_item_type& item);

void main_draw(hero_type& hero, game_fon_type& fon, bullet_type& bullets, game_item_type& item, fleet_type& fleet);


void init_text_type(mySDL& mysdl, text_type& game_text);

void show_pause(const text_type& text);

#endif