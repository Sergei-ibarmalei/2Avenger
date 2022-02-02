#include "sdl_init.hpp"
#include "hero.hpp"
#include "starsky.hpp"
#include "backgrounds.hpp"
//#include "bullet.hpp"
#include "hero_bullet_list.hpp"

static mySDL mysdl;
static SDL_Event e;
static GAME_HISTORY_NAMES history = GAME_HISTORY_NAMES::FIRST;


void check_ship_move(SDL_Event& e, Hero& hero);
void draw(Drawable& object);
void draw_sky(Starsky& sky);
void draw_backs(Backgrounds& backs, GAME_HISTORY_NAMES history);


int main(int argc, char* argv[])
{
    if(!init(mysdl, "2Avenger")) return 1;
    Hero hero(mysdl.gRenderer, "ships_2.png");
    Starsky sky(mysdl.gRenderer, "one_star.png");
    Backgrounds backs(mysdl.gRenderer);
    Bullet bullet(mysdl.gRenderer, "blue_bullet_1.png");
    Bullet_hero_list b_h_list;
    if (!hero.Init_status()) return 1; 
    if (!sky.Init_status()) return 1;
    if (!backs.Init_status()) return 1;
    if (!bullet.Init_status()) return 1;
    if(!b_h_list.Init_status()) return 1;
    

    bool quit = false;

    while(!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT) quit = true;
            else if (e.type == SDL_KEYDOWN)
            {
                check_ship_move(e, hero);
            }
            else if (e.type == SDL_KEYUP)
            {
                switch (e.key.keysym.sym)
                {
                    case SDLK_UP:
                    case SDLK_DOWN:
                    {
                        hero.Position() = hero_position::CENTER;
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
        sky.move();
        draw(hero);
        SDL_RenderPresent(mysdl.gRenderer);
    }
    return 0;
}

void draw(Drawable& object)
{
    object.draw_();
}


//Отрисовка звездного неба в движении
void draw_sky(Starsky& sky)
{
    auto ptr_slow = &sky.Slow_stars()[0];
    auto ptr_fast = &sky.Fast_stars()[0];
    for (;;ptr_slow++, ptr_fast++)
    {
        if(ptr_slow == &sky.Slow_stars()[SLOW_STAR]) break;
        draw(*ptr_slow);
        draw(*ptr_fast);
    }
}

//Отрисовка заднего фона
void draw_backs(Backgrounds& backs, GAME_HISTORY_NAMES history)
{
    auto ptr = &backs.All_back_fons()[static_cast<int>(history)];
    draw(*ptr);
}

//Проверка нажатия клавиш для движения героя
void check_ship_move(SDL_Event& e, Hero& hero)
{
    switch (e.key.keysym.sym)
    {
        case SDLK_UP:
        {
            hero.Position() = hero_position::UP;
            hero.Direction() = Move_direction::UP;
            hero.move_();
            break;
        }
        case SDLK_DOWN:
        {
            hero.Position() = hero_position::DOWN;
            hero.Direction() = Move_direction::DOWN;
            hero.move_();
            break;
        }
        case SDLK_LEFT:
        {
            hero.Position() = hero_position::CENTER;
            hero.Direction() = Move_direction::LEFT;
            hero.move_();
            break;
        }
        case SDLK_RIGHT:
        {
            hero.Position() = hero_position::CENTER;
            hero.Direction() = Move_direction::RIGHT;
            hero.move_();
            break;
        }
        default: {}

    }
}

