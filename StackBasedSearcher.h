//
// Created by frieddv on 1/13/19.
//

#ifndef PROJ2_STACKBASEDSEARCHER_H
#define PROJ2_STACKBASEDSEARCHER_H

#include "ISearcher.h"
#include <stack>
#include <unordered_set>


template <class solution, class T>

class StackBasedSearcher : public ISearcher<solution, T> {
private:

    unsigned long evaluatedNodes;

protected:

    std::stack<State<T>*> openList;
    std::unordered_set<State<T>*> closedList;

    State<T> *popOpenList() {
        ++evaluatedNodes;
        State<T> *result = openList.top();
        openList.pop();
        return result;
    }


};


#endif //PROJ2_STACKBASEDSEARCHER_H
