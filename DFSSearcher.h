//
// Created by frieddv on 1/15/19.
//

#ifndef PROJ2_DFSSEARCHER_H
#define PROJ2_DFSSEARCHER_H

#include "StackBasedSearcher.h"
#include <string>

template <class solution, class T>

class DFSSearcher: public StackBasedSearcher<solution, T> {

public:
    virtual std::string search(ISearchable<T> *searchable) {
        this->addToOpenList(searchable->getInitialState());
        //as long there is a node in the queue
        while (this->getOpenListSize() > 0) {
            State<T> *nodeToDevelop = this->popOpenList();
            if (*nodeToDevelop == *searchable->getGoalState()) {
                string result = this->backTrace(nodeToDevelop, searchable);
                this->deleteEverything();
                return result;
            }
            if (!this->isInClosedList(nodeToDevelop)) {
                this->closedList.push_back(nodeToDevelop);
            }

            std::vector<State<T>*> successors = searchable->getPossibleNextStates(*nodeToDevelop);
            for (auto successor : successors) {
                if (!this->isInClosedList(successor) && !this->isInOpenList(successor)) {
                    this->addToOpenList(successor);
                }
            }
        }
        this->deleteEverything();
        return "-1";
    }
};


#endif //PROJ2_DFSSEARCHER_H
