//
// Created by frieddv on 1/15/19.
//

#ifndef PROJ2_DFSSEARCHER_H
#define PROJ2_DFSSEARCHER_H

#include "StackBasedSearcher.h"

template <class solution, class T>

class DFSSearcher: public StackBasedSearcher<solution, T> {

public:
    virtual std::queue<State<T>*> search(ISearchable<T> *searchable) {
        this->addToOpenList(searchable->getInitialState());
        //as long there is a node in the queue
        while (this->getOpenListSize() > 0) {
            State<T> *nodeToDevelop = this->popOpenList();
            if (*nodeToDevelop == *searchable->getGoalState()) {
                return this->backTrace(nodeToDevelop, searchable);
            }
            if (!this->isInClosedList(nodeToDevelop)) {
                this->addToCloseList(nodeToDevelop);
            }

            std::vector<State<T>*> successors = searchable->getPossibleNextStates(nodeToDevelop);
            for (auto successor : successors) {
                if (!this->isInClosedList(successor) && !this->isInOpenList(successor)) {
                    this->addToOpenList(successor);
                }
            }
        }
        return NULL;
    }
};


#endif //PROJ2_DFSSEARCHER_H
