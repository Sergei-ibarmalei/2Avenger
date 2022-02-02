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

void Bullet_hero_list::Push_back(const Bullet& bullet)
{
    Bullet_hero_listNode* p = new Bullet_hero_listNode{bullet};
    if(!p->pbullet.Init_status()) init = false;
    if (Is_empty())
    {
        first = p;
        last = p;
        return;
    }
    last->next = p;
    last = p;
}