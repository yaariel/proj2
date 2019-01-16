//
// Created by frieddv on 1/9/19.
//

#ifndef PROJ2_ISEARCHABLE_H
#define PROJ2_ISEARCHABLE_H

#include <vector>
#include "State.h"

using namespace std;

template <class T>

class ISearchable {

public:

    virtual State<T> *getInitialState() = 0;

    virtual State<T> *getGoalState() = 0;

    virtual vector<State<T>*> getPossibleNextStates(State<T> &current) = 0;

    virtual vector<State<T>*> getPossibleNextStates(State<T> &current, State<T> &goal) = 0;
};


#endif //PROJ2_ISEARCHABLE_H
