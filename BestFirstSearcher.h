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
                string result = this->backTrace(nodeToDevelop, searchable);
                this->deleteEverything();
                return result;
            }

            //State<T> *father = new State<T>(*nodeToDevelop);
            std::vector<State<T>*> successors = searchable->getPossibleNextStates(*nodeToDevelop);
            for (auto successor : successors) {
                if (!this->isInClosedList(successor) && !this->isInOpenList(successor)) {
                    successor->setFather(nodeToDevelop);
                    this->addToOpenList(successor);
                } else if (!this->isInOpenList(successor)) {
                    this->updateStatePriority(successor);
                }
            }
        }
        this->deleteEverything();
        return "-1";
    }

};


#endif //PROJ2_BESTFIRSTSEARCHER_H
