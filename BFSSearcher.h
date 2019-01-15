//
// Created by frieddv on 1/15/19.
//

#ifndef PROJ2_BFSSEARCHER_H
#define PROJ2_BFSSEARCHER_H

#include "QueueBasedSearcher.h"

template <class solution, class T>

class BFSSearcher : public QueueBasedSearcher<solution, T>{

public:

    virtual solution search(ISearchable<T> *searchable) {
        addToOpenList(searchable->getInitialState());
        //as long there is a node in the queue
        while (this->getOpenListSize() > 0) {
            State<T> *nodeToDevelop = this->popOpenList();
            if (*nodeToDevelop == *searchable->getGoalState()) {
                return backTrace(nodeToDevelop, searchable);
            }
            State<T> *father = new State<T>(*nodeToDevelop);
            std::vector<State<T>*> successors = searchable->getPossibleNextStates(father);

        }
    }
};


#endif //PROJ2_BFSSEARCHER_H
