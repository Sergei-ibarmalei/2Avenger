#include "object_list.hpp"


void draw_node(Drawable_listNode* node)
{
    if (!node) return;
    draw(*node->object);
    node = node->next;
    draw_node(node);
}


//Движение выстрелов из списка в рекурсии
void move_node(Drawable_listNode* node, bool& time_to_cleanup_bhl)
{
    if (!node) return;
    node->object->move_();
    if (!node->object->Is_visible()) 
    {
        time_to_cleanup_bhl = true;
    }
    node = node->next;
    move_node(node, time_to_cleanup_bhl);
}