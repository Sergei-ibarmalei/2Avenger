#include "engine.hpp"
#include "sdl_init.hpp"

static mySDL mysdl;


int main(int argc, char* argv[])
{
    hero_type hero;
    game_fon_type game_fon; 
    bullet_type bulletList;
    fleet_type fleet;
    game_item_type game_item;
    text_type game_text;


    if(!init(mysdl, "2Avenger")) return 1;
    init_hero_type(hero, mysdl, "ships_2.png");
    init_game_fon_type(game_fon, mysdl, "one_star.png");
    init_bullet_list(mysdl, bulletList);
    init_fleet_type(fleet, mysdl, "small_alien.png");
    init_game_item_type(game_item);
    init_text_type(mysdl,  game_text);

    if (!mysdl.all_init_ok) return 1;

    while (!game_item.game_quit)
    {

        while (SDL_PollEvent(&mysdl.e))
        {
            if (mysdl.e.type == SDL_QUIT) game_item.game_quit = true;

            else if (mysdl.e.type == SDL_KEYDOWN)
            {
                check_ship_move(mysdl, hero, bulletList, game_item);
            }
            else if (mysdl.e.type == SDL_KEYUP)
            {
                switch (mysdl.e.key.keysym.sym)
                {
                    case SDLK_UP:
                    case SDLK_DOWN:
                    {
                        hero.hero->Position() = hero_position::CENTER;
                        hero.hero->Bullet_start_position();
                        break;
                    }
                    default: {}
                }
            }

        }


        SDL_SetRenderDrawColor(mysdl.gRenderer, 0x0, 0x0, 0x0, 0xFF);
        SDL_RenderClear(mysdl.gRenderer);
        if (hero.hero->Is_walking_intro()) 
        {

            Hero_walking_intro(mysdl, hero, game_fon, game_item);
            continue;
        }
        main_draw(hero, game_fon, bulletList, game_item, fleet);
        if (game_item.game_paused)
        {
            show_pause(mysdl, game_text);
            continue;
        }

        move_node(bulletList.HeroBulletList->First(), bulletList.time_to_cleanup_bhl); 
        if (bulletList.time_to_cleanup_bhl)
        {
            bulletList.HeroBulletList->CleanUP_from_invisible();
            bulletList.time_to_cleanup_bhl = false;
        }
        fleet.three_alien_fighter->Move(fleet.time_to_cleanup_fleet);
        //show_pause(game_text);
        SDL_RenderPresent(mysdl.gRenderer);
    }
    close_fon(game_fon);
    close_hero(hero);
    close_fleet(fleet);
    close_bullet_list(bulletList);
    close_game_text(game_text);
    

    close(mysdl);
    return 0;
}









