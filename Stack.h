//
// Created by user on 12.02.2020.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H


class Stack{
public:
    virtual bool push_back(int d) = 0;
    virtual int pop_back() = 0;
    virtual bool show() = 0;
};


#endif //STACK_STACK_H
