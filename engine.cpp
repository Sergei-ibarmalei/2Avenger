#include "engine.hpp"



Starsky* init_sky(mySDL& mysdl, const string& file_name)
{
    Starsky* sky = new Starsky {mysdl.gRenderer, file_name};
    if (!sky->Init_status())
    {
        delete sky;
        sky = nullptr;
        mysdl.all_init_ok = false;
        return sky;
    }
    return sky;
}

void draw_sky(Starsky* sky)
{
    auto ptr_slow = &sky->Slow_stars()[0];
    auto ptr_fast = &sky->Fast_stars()[0];
    for (;;ptr_slow++, ptr_fast++)
    {
        if(ptr_slow == &sky->Slow_stars()[SLOW_STAR]) break;
        draw(*ptr_slow);
        draw(*ptr_fast);
    }
}

Backgrounds* init_backs(mySDL& mysdl)
{
    Backgrounds* backs = new Backgrounds {mysdl.gRenderer};
    if (!backs->Init_status())
    {
        delete backs;
        backs = nullptr;
        mysdl.all_init_ok = false;
        return backs;
    }
    return backs;
}

Fl* init_fleet(mySDL& mysdl, const string& file_name, int count)
{
    Fl* fleet = new Fl {mysdl.gRenderer, file_name, count};
    if (!fleet->Init_status())
    {
        delete fleet;
        fleet = nullptr;
        mysdl.all_init_ok = false;
        return fleet;
    }
    return fleet;
}


Object_list<Drawable_listNode>* init_hero_bullet_list()
{
    Object_list<Drawable_listNode>* heroBulletList = new Object_list<Drawable_listNode> {};
    return heroBulletList;
}


void close_bullet_list(Object_list<Drawable_listNode>* l)
{
    delete l;
    l = nullptr;
}

//Проверка нажатия клавиш для движения героя
void check_ship_move(mySDL& mysdl, SDL_Event& e, Hero* hero, Object_list<Drawable_listNode>* hero_bullet_list, bool& quit)
{
    switch (e.key.keysym.sym)
    {
        case SDLK_UP:
        {
            hero->Position() = hero_position::UP;
            hero->Direction() = Move_direction::UP;
            hero->move_();
            break;
        }
        case SDLK_DOWN:
        {
            hero->Position() = hero_position::DOWN;
            hero->Direction() = Move_direction::DOWN;
            hero->move_();
            break;
        }
        case SDLK_LEFT:
        {
            hero->Position() = hero_position::CENTER;
            hero->Direction() = Move_direction::LEFT;
            hero->move_();
            break;
        }
        case SDLK_RIGHT:
        {
            hero->Position() = hero_position::CENTER;
            hero->Direction() = Move_direction::RIGHT;
            hero->move_();
            break;
        }
        case SDLK_SPACE:
        {
            Bullet* b = new Bullet(mysdl.gRenderer, "blue_bullet_1.png", hero->Bullet_start_position(), Bullet_direction::RIGHT);
            if (!b->Init_status()) quit = true;
            hero_bullet_list->Push_back(b);
            break;
        }
        default: {}

    }
}







void draw_backs(Backgrounds* backs, GAME_HISTORY_NAMES history)
{
    auto ptr = &backs->All_back_fons()[static_cast<int>(history)];
    draw(*ptr);
}

void close_hero_sky_backs(Hero* h, Starsky* s, Backgrounds* b)
{
    delete s;
    s = nullptr;
    delete b;
    b = nullptr;
    delete h;
    h = nullptr;
    
}

Hero* init_hero(mySDL& mysdl, const string& file_name)
{
    Hero* hero = new Hero {mysdl.gRenderer, file_name};
    if (!hero->Init_status())
    {
        delete hero;
        hero = nullptr;
        mysdl.all_init_ok = false;
        return hero;
    }
    return hero;
}


void close_fleet(Fl* f)
{
    delete f;
    f = nullptr;
}