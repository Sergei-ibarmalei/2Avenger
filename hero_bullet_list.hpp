#ifndef HERO_BULLET_LIST_HPP
#define HERO_BULLET_LIST_HPP

#include "bullet.hpp"

struct Bullet_hero_listNode
{
    Bullet* bullet;
    Bullet_hero_listNode* next = nullptr;

    Bullet_hero_listNode(Bullet* pb): bullet(pb) {}
    ~Bullet_hero_listNode()
    {
        delete bullet;
        bullet = nullptr;
    }
};


class Bullet_hero_list
{
    Bullet_hero_listNode* first;
    Bullet_hero_listNode* last;

 
    bool Is_empty();
    bool init = true;

    public:
    Bullet_hero_list();
    Bullet_hero_list(const Bullet_hero_list&  ) {}
    ~Bullet_hero_list();
    void Push_back(Bullet* pbullet);
    bool Init_status() const {return init;}
    Bullet_hero_listNode* First() {return first;}
    void SetFirst(Bullet_hero_listNode* f) { first = f;}


};


#endif