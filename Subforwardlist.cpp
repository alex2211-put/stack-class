//
// Created by user on 12.02.2020.
//
#include <iostream>
#include "Subforwardlist.h"

int Subforwardlist::pop_back() {

        Subforwardlist* p = nullptr;
        Subforwardlist* a = next;
        while (a->next != nullptr)
        {
            p = a;
            a = a->next;
        }
        a = p;
        if (a != nullptr)
        {
            int j = a->next->data;
            a->next = nullptr;
            std::cout << j;
            return j;
        } else std::cout << "Error";
        return 0;
    };
bool Subforwardlist::push_back(int d)
{
    Subforwardlist* a = next;
    if (next == nullptr)
    {
        next = new Subforwardlist;
        (next)->next = nullptr;
        (next)->data = d;
    } else
    {
        while (a->next != nullptr)
        {
            a = a->next;
        }
        a->next = new Subforwardlist;
        a = a->next;
        a->data = d;
        a->next = nullptr;
    }
    return true;
};
bool Subforwardlist::show()
{
    Subforwardlist* a = next;
    while (a->next != nullptr)
    {
        std::cout << a->data << " ";
        a = a->next;
    }
    std::cout << a->data;
    return true;
};
bool Subforwardlist::push_forward(int d)
{
    Subforwardlist* b = next;
    next = new Subforwardlist;
    (next)->data = d;
    (next)->next = b;
    return true;
};
int Subforwardlist::pop_forward()
{
    Subforwardlist* b = next;
    std::cout << b->data;
    next = b->next;
    return 0;
};
bool Subforwardlist::push_where(unsigned int where, int d)
{
    int s = 1;
    Subforwardlist *a = next;
    while (s != where)
    {
        a = a->next;
        s++;
    }
    Subforwardlist *b = a->next;
    a->next = new Subforwardlist;
    a->data = d;
    a->next = b;
    return true;
};
bool Subforwardlist::erase_where(unsigned where)
{
    Subforwardlist *a = next;
    Subforwardlist *b;
    int s = 1;
    while (s != where - 1)
    {
        a = a->next;
        s++;
    }
    b = a->next->next;
    a->next = nullptr;
    a->next = b;
    return true;
};
unsigned int Subforwardlist::size()
{
    Subforwardlist *a = next;
    unsigned int s = 0;
    while (a != nullptr)
    {
        a = a->next;
        s++;
    }
    std::cout << s;
    return s;
};
void Subforwardlist::clear()
{
    Subforwardlist *a = next;
    while (a->next != nullptr)
    {
        a->data = 0;
        a->next = nullptr;

    }
};