#include "hero_bullet_list.hpp"

Bullet_hero_list::Bullet_hero_list()
{
    first = last = nullptr;
}

Bullet_hero_list::~Bullet_hero_list()
{

    while (first)
    {
        Bullet_hero_listNode* tmp = first->next;
        delete first;
        first = tmp;
    } 
}

bool Bullet_hero_list::Is_empty()
{
    return first == nullptr;
}

void Bullet_hero_list::Push_back(Bullet* pbullet)
{
    Bullet_hero_listNode* p = new Bullet_hero_listNode{pbullet};
    if (Is_empty())
    {
        first = p;
        last = p;
        return;
    }
    last->next = p;
    last = p;
}

void Bullet_hero_list::CleanUP_from_invisible()
{
    delete_invisible(&first);
}

void Bullet_hero_list::delete_invisible(Bullet_hero_listNode** pcur)
{
    while (*pcur)
    {
        if ( !(*pcur)->bullet->Is_visible())
        {
            Bullet_hero_listNode* tmp = *pcur;
            *pcur = (*pcur)->next;
            delete tmp;
        }
        else
        {
            pcur = &(*pcur)->next;
        }
    }
}