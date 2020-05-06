//
// Created by user on 12.02.2020.
//
#include <iostream>
#include "Subforwardlist.h"

int Subforwardlist::pop_back()
{

    std::shared_ptr<Subforwardlist> p = nullptr;
    std::shared_ptr<Subforwardlist> a = next;
    if (a == nullptr)
    {
        return 0;
    }
    if (a->next != nullptr)
    {
        while (a->next != nullptr)
        {
            p = a;
            a = a->next;
        }
    }
    if (p != nullptr)
        a = p;
    if (a->next != nullptr)
    {
        int j = a->next->data;
        a->next = nullptr;
        return j;
    } else
    {
        int j = next->data;
        next = nullptr;
        return j;
    }
};

bool Subforwardlist::push_back(int d)
{
    std::shared_ptr<Subforwardlist> a = next;
    if (next == nullptr)
    {
        next = std::shared_ptr<Subforwardlist>(new Subforwardlist);
        (next)->next = nullptr;
        (next)->data = d;
    } else
    {
        while (a->next != nullptr)
        {
            a = a->next;
        }
        a->next = std::shared_ptr<Subforwardlist>(new Subforwardlist);
        a->next->data = d;
        a->next->next = nullptr;
    }
    return true;
};

bool Subforwardlist::show()
{
    std::shared_ptr<Subforwardlist> a = next;
    while (a->next != nullptr)
    {
        a = a->next;
    }
    return true;
};

bool Subforwardlist::push_forward(int d)
{
    if (next != nullptr)
    {
        std::shared_ptr<Subforwardlist> b = next;
        next = std::shared_ptr<Subforwardlist>(new Subforwardlist);
        (next)->data = d;
        (next)->next = b;
        return true;
    } else
    {
        next = std::shared_ptr<Subforwardlist>(new Subforwardlist);
        (next)->data = d;
        next->next = nullptr;
        return true;
    }
};

int Subforwardlist::pop_forward()
{
    if (next != nullptr)
    {
        int s = next->data;
        if (next->next != nullptr)
        {
            std::shared_ptr<Subforwardlist> b = next;
            std::shared_ptr<Subforwardlist> a = next;
            a = a->next;
            next = a;
        }
        else {
            next = nullptr;
        }
        return s;
    } else return 0;
};

bool Subforwardlist::push_where(unsigned int where, int d)
{
    if (where == 0)
    {
        std::shared_ptr<Subforwardlist> a = next;
        next = std::shared_ptr<Subforwardlist>(new Subforwardlist);
        (next)->data = d;
        (next)->next = a;
        return true;
    } else
    {
        int s = 0;
        std::shared_ptr<Subforwardlist> a = next;
        std::shared_ptr<Subforwardlist> b = a;
        while (s != where && a->next != nullptr)
        {
            b = a;
            a = a->next;
            s++;
        }
        std::shared_ptr<Subforwardlist> c = a;
        a = std::shared_ptr<Subforwardlist>(new Subforwardlist);
        a->data = d;
        a->next = c;
        b->next = a;
        return true;
    }
};

bool Subforwardlist::erase_where(unsigned where)
{
    if (where == 0)
    {
        if (next->next != nullptr)
        {
            {
                next = next->next;
            }
        } else next = nullptr;
        return true;
    } else
    {
        std::shared_ptr<Subforwardlist>  a = next;
        std::shared_ptr<Subforwardlist>  b = nullptr;
        int s = 0;
        while (s != where - 1)
        {
            b = a;
            a = a->next;
            s++;
        }
        if (a->next == nullptr)
        {
            b->next = nullptr;
            return true;
        }
        b = a->next->next;
        a->next = b;
        return true;
    }
};

unsigned int Subforwardlist::get_size()
{
    std::shared_ptr<Subforwardlist>  a = next;
    unsigned int s = 0;
    while (a != nullptr)
    {
        s++;
        a = a->next;
    }
    return s;
};

void Subforwardlist::clear()
{
    next = nullptr;
};