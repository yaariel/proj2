//
// Created by frieddv on 1/10/19.
//

#ifndef PROJ2_MYMATRIXPROBLEM_H
#define PROJ2_MYMATRIXPROBLEM_H


#include "ISearchable.h"
template <class T>

class MyMatrixSearchable: public ISearchable<T> {

public:
    virtual State<T> getInitialState();

    virtual bool isGoalState(const State<T> &current) {
        return false;
    }

    virtual std::vector<State<T>> getAllPossibleStates(State<T> &current) {
        return std::vector<State<T>>();
    }
};


#endif //PROJ2_MYMATRIXPROBLEM_H
