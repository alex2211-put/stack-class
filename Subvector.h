//
// Created by user on 12.02.2020.
//
//
#ifndef STACK_SUBVECTOR_H
#define STACK_SUBVECTOR_H
#include "Stack.h"

class Subvector: private Stack{
private:
    int *mas;
    unsigned int top;
    unsigned int capacity;
public:
    Subvector();
    ~Subvector();
    bool push_back (int d) override;
    int pop_back() override;
    bool resize(unsigned int new_capacity);
    void shrink_to_fit();
    void clear();
    bool init_from_file(char *filename);
    bool show();
    unsigned int get_capacity();
};

#endif //STACK_SUBVECTOR_H
