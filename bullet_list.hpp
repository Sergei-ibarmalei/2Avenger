#ifndef BULLET_LIST_HPP
#define BULLET_LIST_HPP

#include "bullet.hpp"

struct Bullet_listNode
{
    Bullet* bullet;
    Bullet_listNode* next = nullptr;

    Bullet_listNode(Bullet* pb): bullet(pb) {}
    ~Bullet_listNode()
    {
        delete bullet;
        bullet = nullptr;
    }
};


class Bullet_list
{
    Bullet_listNode* first;
    Bullet_listNode* last;

 
    bool Is_empty();
    void delete_invisible(Bullet_listNode** pcur);

    public:
    Bullet_list();
    Bullet_list(const Bullet_list&  ) {}
    ~Bullet_list();
    void Push_back(Bullet* pbullet);
    Bullet_listNode* First() {return first;}
    void SetFirst(Bullet_listNode* f) { first = f;}
    void CleanUP_from_invisible();


};


#endif