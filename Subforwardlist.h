//
// Created by user on 12.02.2020.
//

#ifndef STACK_SUBFORWARDLIST_H
#define STACK_SUBFORWARDLIST_H

#include <memory>
#include "Stack.h"

class Subforwardlist : private Stack
{
private:
    int data;
    std::shared_ptr<Subforwardlist> next;
public:
    Subforwardlist()
    {
        data = 0;
        next = nullptr;
    }

    ~Subforwardlist()
    {
        std::shared_ptr<Subforwardlist> a = next;
        if (next != nullptr)
            while (next->next != nullptr)
            {
                next = next->next;
                a = next;
            }
    }

    int pop_back() override;

    bool push_back(int d) override;

    bool show() override;

    bool push_forward(int d);

    int pop_forward();

    bool push_where(unsigned int where, int d);

    bool erase_where(unsigned where);

    unsigned int get_size();

    void clear();
};


#endif //STACK_SUBFORWARDLIST_H
