//
// Created by frieddv on 1/9/19.
//

#ifndef PROJ2_ISEARCHABLE_H
#define PROJ2_ISEARCHABLE_H

#include <vector>
#include "State.h"

template <class T>

class ISearchable {
public:
    virtual State<T> getInitialState() = 0;
    virtual bool isGoalState(const State<T> &current) = 0;
    virtual std::vector<State<T>> getAllPossibleStates(State<T> &current) = 0;
};


#endif //PROJ2_ISEARCHABLE_H
