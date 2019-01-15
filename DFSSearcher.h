//
// Created by frieddv on 1/15/19.
//

#ifndef PROJ2_DFSSEARCHER_H
#define PROJ2_DFSSEARCHER_H

#include "StackBasedSearcher.h"

template <class solution, class T>

class DFSSearcher: public StackBasedSearcher<solution, T> {

public:
    virtual solution search(ISearchable<T> *searchable) {
        addToOpenList(searchable->getInitialState());
        //as long there is a node in the queue
        while (this->getOpenListSize() > 0) {
            State<T> *nodeToDevelop = this->popOpenList();
            if (*nodeToDevelop == *searchable->getGoalState()) {
                return backTrace(nodeToDevelop, searchable);
            }
            if (!isInClosedList(nodeToDevelop)) {
                addToCloseList(nodeToDevelop);
            }

            std::vector<State<T>*> successors = searchable->getPossibleNextStates(nodeToDevelop);
            for (auto successor : successors) {
                if (!isInClosedList(successor) && !isInOpenList(successor)) {
                    addToOpenList(successor);
                }
            }
        }
        // return error or any kind of minus 1 as not having route
    }
};


#endif //PROJ2_DFSSEARCHER_H
