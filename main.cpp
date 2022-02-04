#include "sdl_init.hpp"
#include "hero.hpp"
#include "starsky.hpp"
#include "backgrounds.hpp"
#include "bullet.hpp"
#include "object_list.hpp"

static mySDL mysdl;
static SDL_Event e;
static GAME_HISTORY_NAMES history = GAME_HISTORY_NAMES::FIRST;

//Пора чистить список выстрелов героя
static bool time_to_cleanup_bhl = false;


//void check_ship_move(SDL_Event& e, Hero& hero, Bullet_list& bhl, bool& quit);
void check_ship_move(SDL_Event& e, Hero& hero, Object_list<Drawable_listNode>& bhl, bool& quit);
void draw(Drawable& object);
void draw_sky(Starsky& sky);
void draw_backs(Backgrounds& backs, GAME_HISTORY_NAMES history);
//void draw_hero_bullets(Bullet_listNode* node);
//void draw_bullets(Bullet_list& hl);
//void draw_hero_bullest(Drawable_listNode* node);
void draw_node(Drawable_listNode* node);
//void hero_move_bullest(Bullet_list& hl, bool& time_to_cleanup_bhl);
//void move_bullets
//void move_bullet_hero(Bullet_listNode* bullet, bool& time_to_cleanup_bhl);
void move_node(Drawable_listNode* node, bool& time_to_cleanup_bhl);

int main(int argc, char* argv[])
{
    if(!init(mysdl, "2Avenger")) return 1;
    Hero hero(mysdl.gRenderer, "ships_2.png");
    Starsky sky(mysdl.gRenderer, "one_star.png");
    Backgrounds backs(mysdl.gRenderer);
    //Список выстрелов героя
    Object_list<Drawable_listNode> HeroBulletList;
    if (!hero.Init_status()) return 1; 
    if (!sky.Init_status()) return 1;
    if (!backs.Init_status()) return 1;
    

    bool quit = false;

    while(!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT) quit = true;
            else if (e.type == SDL_KEYDOWN)
            {
                check_ship_move(e, hero, HeroBulletList, quit);
            }
            else if (e.type == SDL_KEYUP)
            {
                switch (e.key.keysym.sym)
                {
                    case SDLK_UP:
                    case SDLK_DOWN:
                    {
                        hero.Position() = hero_position::CENTER;
                        hero.Bullet_start_position();
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
        draw_node(HeroBulletList.First());
        move_node(HeroBulletList.First(), time_to_cleanup_bhl);
        if (time_to_cleanup_bhl)
        {
            HeroBulletList.CleanUP_from_invisible();
            time_to_cleanup_bhl = false;
        }
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
    //Берем картинку в зависимости от значения переменной history
    auto ptr = &backs.All_back_fons()[static_cast<int>(history)];
    draw(*ptr);
}

//Проверка нажатия клавиш для движения героя
void check_ship_move(SDL_Event& e, Hero& hero, Object_list<Drawable_listNode>& hero_bullet_list, bool& quit)
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
        case SDLK_SPACE:
        {
            Bullet* b = new Bullet(mysdl.gRenderer, "blue_bullet_1.png", hero.Bullet_start_position(), Bullet_direction::RIGHT);
            if (!b->Init_status()) quit = true;
            hero_bullet_list.Push_back(b);
            break;
        }
        default: {}

    }
}



void draw_node(Drawable_listNode* node)
{
    if (!node) return;
    draw(*node->object);
    node = node->next;
    draw_node(node);
}


//Движение выстрелов из списка в рекурсии
void move_node(Drawable_listNode* node, bool& time_to_cleanup_bhl)
{
    if (!node) return;
    node->object->move_();
    if (!node->object->Is_visible()) 
    {
        time_to_cleanup_bhl = true;
    }
    node = node->next;
    move_node(node, time_to_cleanup_bhl);
}

