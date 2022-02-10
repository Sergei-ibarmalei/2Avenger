#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "drawable.hpp"
//#include "hero.hpp"
//#include "object_list.hpp"
//#include "bullet.hpp"
#include "mysdl.hpp"
#include "starsky.hpp"
#include "backgrounds.hpp"
#include "consts.hpp"


void draw(Drawable& object);


Starsky* init_sky(mySDL& mysdl, const string& file_name);

Backgrounds* init_backs(mySDL& mysdl);

void draw_sky(Starsky* sky);

void draw_backs(Backgrounds* backs, GAME_HISTORY_NAMES history);

#endif