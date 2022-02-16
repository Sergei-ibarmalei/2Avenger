#ifndef OBJECT_LIST_HPP
#define OBJECT_LIST_HPP

#include "drawable.hpp"


//Узел для текстуры основной игры
struct Drawable_listNode
{
    Drawable* object;
    Drawable_listNode* next = nullptr;

    Drawable_listNode(Drawable* pd): object(pd) {}
    ~Drawable_listNode()
    {
        delete object;
        object = nullptr;
    }
};

struct DeckTexture_listNode
{
    DeckTexture* object;
    DeckTexture_listNode* next = nullptr;

    DeckTexture_listNode(DeckTexture* pd): object(pd) {}
    ~DeckTexture_listNode()
    {
        delete object;
        object = nullptr;
    }
};


void draw_node(Drawable_listNode* node);
void move_node(Drawable_listNode* node, bool& time_to_cleanup_bhl);

template <class T>
class Object_list
{
    T* first;
    T* last;

    bool Is_empty();
    void delete_invisibles(T** pcur);

    public:
    Object_list();
    Object_list(const T&) {}
    ~Object_list();
    void Push_back(Drawable* object);
    T* First() {return first;}
    void CleanUP_from_invisible();
};


template <class T>
Object_list<T>::Object_list()
{
    first = last = nullptr;
}

template <class T>
Object_list<T>::~Object_list()
{
    while(first)
    {
        T* tmp = first->next;
        delete first;
        first = tmp;
    }
}

template <class T>
bool Object_list<T>::Is_empty()
{
    return first == nullptr;
}

template <class T>
void Object_list<T>::Push_back(Drawable* object)
{
    T* p = new T {object};
    if (Is_empty())
    {
        first = last = p;
        return;
    }
    last->next = p;
    last = p;
}

template <class T>
void Object_list<T>::CleanUP_from_invisible()
{
    delete_invisibles(&first);
}

template <class T>
void Object_list<T>::delete_invisibles(T** pcur)
{
    while(*pcur)
    {
        if (!(*pcur)->object->Is_visible())
        {
            T* tmp = *pcur;
            *pcur = (*pcur)->next;
            delete tmp;
        }
        else
        {
            pcur = &(*pcur)->next;
        }
    }
}






#endif