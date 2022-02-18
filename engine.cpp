#include "engine.hpp"

Hero* init_hero(mySDL& mysdl, const string& file_name);
Backgrounds* init_backs(mySDL& mysdl);
Starsky* init_sky(mySDL& mysdl, const string& file_name);
//Object_list<Drawable_listNode>* init_hero_bullet_list();
Fl* init_fleet(mySDL& mysdl, const string& file_name, int count);
Ltexture* init_text(mySDL& mysdl, const string& text, const int size, const SDL_Color& col);



//Проверка нажатия клавиш для движения героя
void check_ship_move(mySDL& mysdl, hero_type& hero, bullet_type& bullet_list, game_item_type& game)
{
    if (hero.hero->Is_walking_intro()) return;
    switch (mysdl.e.key.keysym.sym)
    {
        case SDLK_ESCAPE:
        {
            if (!game.game_paused) game.game_paused = true;
            else game.game_paused = false;
            break;
        }
        case SDLK_UP:
        {
            if (game.game_paused) return;
            hero.hero->Position() = hero_position::UP;
            hero.hero->Direction() = Move_direction::UP;
            hero.hero->move_();
            break;
        }
        case SDLK_DOWN:
        {
            if (game.game_paused) return;
            hero.hero->Position() = hero_position::DOWN;
            hero.hero->Direction() = Move_direction::DOWN;
            hero.hero->move_();
            break;
        }
        case SDLK_LEFT:
        {
            if (game.game_paused) return;
            hero.hero->Position() = hero_position::CENTER;
            hero.hero->Direction() = Move_direction::LEFT;
            hero.hero->move_();
            break;
        }
        case SDLK_RIGHT:
        {
            if (game.game_paused) return;
            hero.hero->Position() = hero_position::CENTER;
            hero.hero->Direction() = Move_direction::RIGHT;
            hero.hero->move_();
            break;
        }
        case SDLK_SPACE:
        {
            if (game.game_paused) return;
            Bullet* b = new Bullet(mysdl.gRenderer, "blue_bullet_1.png", hero.hero->Bullet_start_position(), Bullet_direction::RIGHT);
            if (!b->Init_status())  game.game_quit = true;
            bullet_list.HeroBulletList->Push_back(b);
            break;
        }
        default: {}

    }
}




void init_hero_type(hero_type& hero, mySDL& mysdl, const string& file_name)
{
    hero.hero = init_hero(mysdl, file_name);
}

Hero* init_hero(mySDL& mysdl, const string& file_name)
{
    Hero* hero = new Hero {mysdl.gRenderer, file_name};
    if (!hero->Init_status())
    {
        delete hero;
        hero = nullptr;
        mysdl.all_init_ok = false;
    }
    return hero;
}



void init_game_fon_type(game_fon_type& gft, mySDL& mysdl, const string& file_name)
{
    gft.backs = init_backs(mysdl);
    gft.sky = init_sky(mysdl, file_name); 
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

void init_bullet_list(mySDL& mysdl, bullet_type& bullets)
{

    bullets.HeroBulletList = new Object_list<Drawable_listNode> {};
    if (!bullets.HeroBulletList) mysdl.all_init_ok = false;
}



void init_fleet_type(fleet_type& fleet, mySDL& mysdl, const string& file_name)
{
    fleet.three_alien_fighter = init_fleet(mysdl, file_name, 3);
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

void init_game_item_type(game_item_type& status)
{
    status.game_part = GAME_HISTORY_PART::FIRST;
}

//Отрисовка заднего фона, звезд, движение звезд
void draw_fon(game_fon_type& fon, const game_item_type& game)
{
    auto ptr_back_image = &fon.backs->All_back_fons()[static_cast<int>(game.game_part)];
    auto ptr_slow_star = &fon.sky->Slow_stars()[0];
    auto ptr_fast_star = &fon.sky->Fast_stars()[0];
    draw(*ptr_back_image);
    for (;;ptr_slow_star++, ptr_fast_star++)
    {
        if (ptr_slow_star == &fon.sky->Slow_stars()[SLOW_STAR]) break;
        draw(*ptr_slow_star);
        draw(*ptr_fast_star);
    }
    fon.sky->move();
    
}



void close_fleet(fleet_type& fleet)
{
    delete fleet.three_alien_fighter;
    fleet.three_alien_fighter = nullptr;
}



void close_bullet_list(bullet_type& bullet_list)
{
    delete bullet_list.HeroBulletList;
    bullet_list.HeroBulletList = nullptr;
    bullet_list.time_to_cleanup_bhl = false;
}



void close_hero(hero_type& hero)
{
    delete hero.hero;
    hero.hero = nullptr;
}

void close_fon(game_fon_type& fon)
{
    delete fon.sky;
    fon.sky = nullptr;
    delete fon.backs;
    fon.backs = nullptr;
}



void Hero_walking_intro(mySDL& mysdl, hero_type& hero, game_fon_type& fon, game_item_type& item)
{
        SDL_SetRenderDrawColor(mysdl.gRenderer, 0x0, 0x0, 0x0, 0xFF);
        SDL_RenderClear(mysdl.gRenderer);
        draw_fon(fon, item);
        fon.sky->move();
        hero.hero->move_();
        draw(*hero.hero);
        //SDL_RenderPresent(mysdl.gRenderer);
}

void main_draw(hero_type& hero, game_fon_type& fon, bullet_type& bullets, game_item_type& item, fleet_type& fleet)
{
    draw_fon(fon, item);
    draw(*hero.hero);
    draw_node(bullets.HeroBulletList->First());
    fleet.three_alien_fighter->Draw();
}

void draw_deck(const mySDL& mysdl, game_gui_type& gui)
{
    gui.deck->draw_decka(mysdl);
    gui.deck->draw_herolives(mysdl);
}



void show_pause(const mySDL& mysdl, const game_gui_type& gui)
{
    //text.pause->render( (S_W - text.pause->get_mTexture_w())/2, (S_H - text.pause->get_mTexture_h())/2);
    gui.text_pause->render( (S_W - gui.text_pause->get_mTexture_w())/2, (S_H - gui.text_pause->get_mTexture_h())/2);
    SDL_RenderPresent(mysdl.gRenderer);
}


Ltexture* init_text(mySDL& mysdl, const string& text, const int size, const SDL_Color& col)
{
    Ltexture* newText = new Ltexture {mysdl.gRenderer, text, size, col};
    if (!newText->get_Ltexture_status())
    {
        mysdl.all_init_ok = false;
        return nullptr;
    }
    return newText;
}

void init_game_gui(mySDL& mysdl, game_gui_type& gui)
{
    SDL_Color pause_color = {0xFF, 0x0, 0x0, 0xFF};
    gui.text_pause = init_text(mysdl, gui.string_pause, TEXT_PAUSE_HEIGHT, pause_color);

    gui.deck = new Decka {mysdl, gui.decka_image, gui.decka_onehero};
    if (!mysdl.all_init_ok) return;
    
}

void close_game_gui(game_gui_type& gui)
{
    delete gui.text_pause;
    gui.text_pause = nullptr;
    delete gui.deck;
    gui.deck = nullptr;
    
}

