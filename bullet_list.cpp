#include "bullet_list.hpp"

Bullet_list::Bullet_list()
{
    first = last = nullptr;
}

Bullet_list::~Bullet_list()
{

    while (first)
    {
        Bullet_listNode* tmp = first->next;
        delete first;
        first = tmp;
    } 
}

bool Bullet_list::Is_empty()
{
    return first == nullptr;
}

void Bullet_list::Push_back(Bullet* pbullet)
{
    Bullet_listNode* p = new Bullet_listNode{pbullet};
    if (Is_empty())
    {
        first = p;
        last = p;
        return;
    }
    last->next = p;
    last = p;
}

void Bullet_list::CleanUP_from_invisible()
{
    delete_invisible(&first);
}

void Bullet_list::delete_invisible(Bullet_listNode** pcur)
{
    while (*pcur)
    {
        if ( !(*pcur)->bullet->Is_visible())
        {
            Bullet_listNode* tmp = *pcur;
            *pcur = (*pcur)->next;
            delete tmp;
        }
        else
        {
            pcur = &(*pcur)->next;
        }
    }
}