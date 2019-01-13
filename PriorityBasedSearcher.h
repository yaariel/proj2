//
// Created by frieddv on 1/11/19.
//

#ifndef PROJ2_PRIORITYBASEDSEARCHER_H
#define PROJ2_PRIORITYBASEDSEARCHER_H

#include "ISearcher.h"
#include <queue>

template <class solution, class T>

class PriorityBasedSearcher : public ISearcher<solution, T> {

    std::priority_queue<T> closedGroup;

public:
};


#endif //PROJ2_PRIORITYBASEDSEARCHER_H
