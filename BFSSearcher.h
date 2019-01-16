//
// Created by frieddv on 1/15/19.
//

#ifndef PROJ2_BFSSEARCHER_H
#define PROJ2_BFSSEARCHER_H

#include "QueueBasedSearcher.h"

template <class solution, class T>

class BFSSearcher : public QueueBasedSearcher<solution, T>{

public:

    virtual string search(ISearchable<T> *searchable) {
        this->addToOpenList(searchable->getInitialState());
        //as long there is a node in the queue
        while (this->getOpenListSize() > 0) {
            State<T> *nodeToDevelop = this->popOpenList();
            if (*nodeToDevelop == *searchable->getGoalState()) {
                string result = this->backTrace(nodeToDevelop, searchable);
                this->deleteEverything();
                return result;
            }

            std::vector<State<T>*> successors = searchable->getPossibleNextStates(*nodeToDevelop);
            for (auto successor : successors) {
                if (!this->isInClosedList(successor)) {
                    this->addToOpenList(successor);
                    this->addToCloseList(successor);
                }

            }
        }
        this->deleteEverything();
        return "-1";
    }
};


#endif //PROJ2_BFSSEARCHER_H
