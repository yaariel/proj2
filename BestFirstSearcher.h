//
// Created by frieddv on 1/14/19.
//

#ifndef PROJ2_BESTFIRSTSEARCHER_H
#define PROJ2_BESTFIRSTSEARCHER_H


#include "PriorityBasedSearcher.h"

template <class solution, class T>

class BestFirstSearcher : public PriorityBasedSearcher<solution, T> {

public:

    virtual string search(ISearchable<T> *searchable) {
        //adding the initalState to the open list.
        this->addToOpenList(searchable->getInitialState());
        while (this->getOpenListSize() > 0) {
            //start develop the node
            State<T> *nodeToDevelop = this->popOpenList();
            this->closedList.push_back(nodeToDevelop);
            //if we got to the goal
            if (*nodeToDevelop == *searchable->getGoalState()) {
                return this->backTrace(nodeToDevelop, searchable);
            }
            //todo: checking if needed to change the constructor
            State<T> *father = new State<T>(*nodeToDevelop);
            std::vector<State<T>*> successors = searchable->getPossibleNextStates(father);
            for (auto *successor : successors) {
                if (!this->isInClosedList(successor) && !this->isInOpenList(successor)) {
                    successor->setFather(*father);
                    this->addToOpenList(successor);
                } else if (!this->isInOpenList(successor)) {
                    this->updateStatePriority(successor);
                }
            }
        }
        return "-1";
    }

};


#endif //PROJ2_BESTFIRSTSEARCHER_H
