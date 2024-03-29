//
// Created by frieddv on 1/10/19.
//

#ifndef PROJ2_ISEARCHER_H
#define PROJ2_ISEARCHER_H

#include "ISearchable.h"

template <class solution, class T>

class ISearcher {
public:

    virtual solution search(ISearchable<T> *searchable) = 0;

    virtual unsigned long getNumberOfNodesEvaluated() = 0;

    virtual ~ISearcher() {}
};


#endif //PROJ2_ISEARCHER_H
