#ifndef HERO_BULLET_LIST_HPP
#define HERO_BULLET_LIST_HPP

#include "bullet.hpp"

struct Bullet_hero_listNode
{
    Bullet pbullet;
    Bullet_hero_listNode* next = nullptr;

    Bullet_hero_listNode(const Bullet b): pbullet(b) {}
    ~Bullet_hero_listNode() {next = nullptr;}
};

/* Bullet_hero_listNode::~Bullet_hero_listNode()
{
    //delete pbullet;
    //pbullet = nullptr;
} */


class Bullet_hero_list
{
    Bullet_hero_listNode* first;
    Bullet_hero_listNode* last;

    //SDL_Renderer* render = nullptr;
    //string fname = "";
    //Bullet_direction direction;
    bool Is_empty();
    bool init = true;

    public:
    Bullet_hero_list();
    //Bullet_hero_list(SDL_Renderer* r, const string& file_name, Bullet_direction dir);
    Bullet_hero_list(const Bullet_hero_list&  ) {}
    ~Bullet_hero_list();
    void Push_back(const Bullet& bullet);
    bool Init_status() const {return init;}


};

//Bullet_hero_list::Bullet_hero_list(SDL_Renderer* r, const string& fn, Bullet_direction dir)
//{
    //render = r;
    //fname = fn;
    //direction = dir;
//}



#endif