//
// Created by user on 12.02.2020.
//
#include <iostream>
#include <fstream>
#include "Subvector.h"

Subvector::Subvector()
{
    capacity = 0;
    top = 0;
    mas = nullptr;
};
Subvector::~Subvector()
{
    capacity = 0;
    top = 0;
    mas = nullptr;
};
bool Subvector::push_back (int d)
{
    int s;
    int *p = mas;
    s = d;
    if (capacity == top)
    {
        capacity++;
        mas = new int[capacity];
        for (int i = 0; i < top; i++)
            *(mas + i) = *(p + i);
        top += 1;
        *(mas + top - 1) = s;
    } else
    {
        top += 1;
        *(mas + top - 1) = s;
    }
    return true;
};
int Subvector::pop_back()
{
    top--;
    return *(mas + top);
};
bool Subvector::resize(unsigned int new_capacity)
{
    capacity += new_capacity;
    int *p = mas;
    mas = new int[capacity];
    for (int i = 0; i < top; i++)
        *(mas + i) = *(p + i);
    return true;
};
void Subvector::shrink_to_fit()
{
    int *p = mas;
    capacity = top;
    for (int i = 0; i < top; i++)
        *(mas + i) = *(p + i);
};
void Subvector::clear()
{
    top = 0;
};
bool Subvector::init_from_file(char *filename)
{
    std::ifstream i(filename);
    int sum = 0;
    if (!i.is_open())
    {
        return false;
    }
    else
    {
        while (!(i.eof()))
        {char s;
            i.get(s);
            sum++;}
    }
    capacity = sum;
    mas = new int [capacity];
    for (top = 0; top < capacity; top++)
    {
        if (!i.is_open())
        {
            return false;
        }
        else
        {
            while (!(i.eof()))
            {
                char s;
                i.get(s);
                *(mas + top) = s;
            }
        }
    }
    return true;
};
bool Subvector::show()
{
    for (int i = 0; i < top; i++)
        std::cout << *(mas + i) << " ";
    return true;
};

