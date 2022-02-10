#include "engine.hpp"
#include "sdl_init.hpp"

static mySDL mysdl;
static SDL_Event e;
static GAME_HISTORY_NAMES history = GAME_HISTORY_NAMES::FIRST;

//Пора чистить список выстрелов героя
static bool time_to_cleanup_hbl = false;
static bool time_to_cleanup_fleet = false;


void check_ship_move(SDL_Event& e, Hero* hero, Object_list<Drawable_listNode>& bhl, bool& quit);
void draw_node(Drawable_listNode* node);
void move_node(Drawable_listNode* node, bool& time_to_cleanup_bhl);

int main(int argc, char* argv[])
{
    if(!init(mysdl, "2Avenger")) return 1;
    Hero* hero = init_hero(mysdl, "ships_2.png");
    Starsky* sky = init_sky(mysdl, "one_star.png");
    Backgrounds* backs = init_backs(mysdl);
    //Список выстрелов героя
    Object_list<Drawable_listNode>* HeroBulletList = init_hero_bullet_list();
    Fl* fleet = init_fleet(mysdl, "small_alien.png", 3);
    if (!mysdl.all_init_ok) return 1;
    
    

    bool quit = false;

    while(!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT) quit = true;
            else if (e.type == SDL_KEYDOWN)
            {
                check_ship_move(mysdl, e, hero, HeroBulletList, quit);
            }
            else if (e.type == SDL_KEYUP)
            {
                switch (e.key.keysym.sym)
                {
                    case SDLK_UP:
                    case SDLK_DOWN:
                    {
                        hero->Position() = hero_position::CENTER;
                        hero->Bullet_start_position();
                        break;
                    }
                    default: {}
                }
            }

        }

        SDL_SetRenderDrawColor(mysdl.gRenderer, 0x0, 0x0, 0x0, 0xFF);
        SDL_RenderClear(mysdl.gRenderer);
        draw_backs(backs, history);
        draw_sky(sky);
        sky->move();
        draw(*hero);
        draw_node(HeroBulletList->First());
        move_node(HeroBulletList->First(), time_to_cleanup_hbl);
        if (time_to_cleanup_hbl)
        {
            HeroBulletList->CleanUP_from_invisible();
            time_to_cleanup_hbl = false;
        }
        fleet->Draw();
        fleet->Move(time_to_cleanup_fleet);
        SDL_RenderPresent(mysdl.gRenderer);
    }
    close_hero_sky_backs(hero, sky, backs);
    close_fleet(fleet);
    close_bullet_list(HeroBulletList);
    

    close(mysdl);
    return 0;
}









