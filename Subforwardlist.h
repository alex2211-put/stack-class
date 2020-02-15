//
// Created by user on 12.02.2020.
//

#ifndef STACK_SUBFORWARDLIST_H
#define STACK_SUBFORWARDLIST_H
#include "Stack.h"

class Subforwardlist: private Stack {
private:
    int data;
    Subforwardlist* next;
public:
    Subforwardlist()
    {
        data = 0;
        next = nullptr;
    }
    int pop_back();
    bool push_back(int d);
    bool show();
    bool push_forward(int d);
    int pop_forward();
    bool push_where(unsigned int where, int d);
    bool erase_where(unsigned where);
    unsigned int size();
    void clear();
};


#endif //STACK_SUBFORWARDLIST_H
