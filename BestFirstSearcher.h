//
// Created by frieddv on 1/14/19.
//

#ifndef PROJ2_BESTFIRSTSEARCHER_H
#define PROJ2_BESTFIRSTSEARCHER_H


#include "PriorityBasedSearcher.h"

template <class solution, class T>

class BestFirstSearcher : public PriorityBasedSearcher<solution, T> {

public:

    solution search(ISearchable<T> *searchable) {
        //adding the initalState to the open list.
        addToOpenList(searchable->getInitialState());
        while (this->getOpenListSize() > 0) {
            //start develop the node
            State<T> *nodeToDevelop = this->popOpenList();
            this->closedList.push_back(nodeToDevelop);
            //if we got to the goal
            if (*nodeToDevelop == *searchable->getGoalState()) {
                return backTrace(nodeToDevelop, searchable);
            }
            //todo: checking if needed to change the constructor
            State<T> *father = new State<T>(*nodeToDevelop);
            std::vector<State<T>*> successors = searchable->getPossibleNextStates(father);
            for (auto *successor : successors) {
                if (!isInClosedList(successor) && !isInOpenList(successor)) {
                    successor->setFather(*father);
                    addToOpenList(successor);
                } else if (!isInOpenList(successor)) {
                    updateStatePriority(successor);
                }
            }
        }
    }

};


#endif //PROJ2_BESTFIRSTSEARCHER_H
