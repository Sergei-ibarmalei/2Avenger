#include "hero_bullet_list.hpp"

Bullet_hero_list::~Bullet_hero_list()
{
    if (first)
    {
        delete first;
    }
    if (last)
    {
        delete last;
    }
    first = nullptr;
    last = nullptr;
    //render = nullptr;
}

bool Bullet_hero_list::Is_empty()
{
    return first == nullptr;
}

void Bullet_hero_list::Push_back(const Bullet& bullet)
{
    Bullet_hero_listNode* p = new Bullet_hero_listNode{bullet};
    if (Is_empty())
    {
        first = p;
        last = p;
        return;
    }
    last->next = p;
    last = p;
}