//
// Created by frieddv on 1/10/19.
//

#ifndef PROJ2_COMPARECOST_H
#define PROJ2_COMPARECOST_H

#include "State.h"

//creating object function for comparing , so we can sort the states

template <class T>

struct CompareCost {
public:
    bool operator()(State<T> left, State<T> right) const {
        return left.getCost() < right.getCost();
    }
};


#endif //PROJ2_COMPARECOST_H
