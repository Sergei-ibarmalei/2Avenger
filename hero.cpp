#include "hero.hpp"

Hero::Hero(SDL_Renderer* r, const string& file_name) : Drawable(r, file_name)
{
    if (!lt->get_Ltexture_status())
    {
        init = false;
        return;
    }
    sprite_width = lt->get_mTexture_w();

    loadMedia();
    position = hero_position::CENTER;
    upleftcorner = {S_W/2 - lt->get_mTexture_w()/2, S_H/2 - sprite_height[CENTERSHIP]/2};
    Set_bullet_start_pos();
}

//Установка стартовой позиции пули
void Hero::Set_bullet_start_pos()
{
    bullet_start_pos.x = upleftcorner.x + sprite_width + BULLET_START_X_SHIFT;
    bullet_start_pos.y = gSprites[static_cast<int>(position)].h / 2;
}

Hero::~Hero()
{
    delete lt;
    lt = nullptr;
}

void Hero::draw_()
{
    //std::cout << "here\n";
    switch(position)
    {
        case hero_position::UP:
        {
            lt->render(upleftcorner.x, upleftcorner.y, &gSprites[UPSHIP]);
            break;
        }
        case hero_position::CENTER:
        {
            lt->render(upleftcorner.x, upleftcorner.y, &gSprites[CENTERSHIP]);
            break;
        }
        case hero_position::DOWN:
        {
            lt->render(upleftcorner.x, upleftcorner.y, &gSprites[DOWNSHIP]);
            break;
        }
        default: {}
    }
}


void Hero::move_()
{
    switch (direction)
    {
        case Move_direction::UP:
        {
            if (is_out_of_border()) return;
            upleftcorner.y -= SHIP_SPEED;
            break;
        }
        case Move_direction::DOWN:
        {
            if (is_out_of_border()) return;
            upleftcorner.y += SHIP_SPEED;
            break;
        }
        case Move_direction::LEFT:
        {
            if (is_out_of_border()) return;
            upleftcorner.x -= SHIP_SPEED;
            break;
        }
        case Move_direction::RIGHT:
        {
            if (is_out_of_border()) return;
            upleftcorner.x += SHIP_SPEED;
            break;
        }
        case Move_direction::NONE:
        default: {}
    }

    Set_bullet_start_pos();
}


void Hero::loadMedia()
{
    gSprites[UPSHIP].x = 0;
    gSprites[UPSHIP].y = 0;
    gSprites[UPSHIP].w = sprite_width;
    gSprites[UPSHIP].h = 24;

    sprite_height[UPSHIP] = gSprites[UPSHIP].h;

    gSprites[CENTERSHIP].x = 0;
    gSprites[CENTERSHIP].y = 26;
    gSprites[CENTERSHIP].w = sprite_width;
    gSprites[CENTERSHIP].h = 28;

    sprite_height[CENTERSHIP] = gSprites[CENTERSHIP].h;

    gSprites[DOWNSHIP].x = 0;
    gSprites[DOWNSHIP].y = 57;
    gSprites[DOWNSHIP].w = sprite_width;
    gSprites[DOWNSHIP].h = 24;

    sprite_height[DOWNSHIP] = gSprites[DOWNSHIP].h;


}

bool Hero::is_out_of_border()
{
    switch (direction)
    {
        case Move_direction::UP:
        {
            return ((upleftcorner.y - SHIP_SPEED) < UP_BORDER); break;
        }
        case Move_direction::DOWN:
        {
            return ((upleftcorner.y + gSprites[CENTERSHIP].h + SHIP_SPEED) > DOWN_BORDER); break;
        }
        case Move_direction::LEFT:
        {
            return ((upleftcorner.x - SHIP_SPEED) < LEFT_BORDER); break;
        }
        case Move_direction::RIGHT:
        {
            return ((upleftcorner.x + sprite_width + SHIP_SPEED) > RIGHT_BORDER); break;
        }
        case Move_direction::NONE:
        default: {}
    }
    return false;
}