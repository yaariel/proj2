//
// Created by frieddv on 1/11/19.
//

#ifndef PROJ2_PRIORITYBASEDSEARCHER_H
#define PROJ2_PRIORITYBASEDSEARCHER_H

#include "ISearcher.h"
#include "CompareCost.h"
#include "State.h"
#include <queue>
#include <set>
#include <unordered_set>

template <class solution, class T>

class PriorityBasedSearcher : public ISearcher<solution, T> {
private:

    unsigned long evaluatedNodes;

protected:

    //maybe the member itself need to move into private section, depends on
    std::multiset<State<T>*, CompareCost<T>> openList;
    std::unordered_set<State<T>*> closedList;

    State<T> *popOpenList() {
        ++evaluatedNodes;
        auto iter = openList.begin();

        implement this!
    }

    solution backTrace(State<T> *current, ISearchable<T> *searchable) {
        implement this!
    }

    unsigned long getOpenListSize() {
        return openList.size();
    }

    void addToOpenList(State<T> *current) {
        openList.insert(current);
    }

    bool isInOpenList(State<T> *current) {
        for (auto state : openList) {
            if (*current == *state) {
                return true;
            }
        }
        return false;
    }

    bool isInClosedList(State<T> *current) {
        for (auto node : closedList) {
            if (*current == *node) {
                return true;
            }
        }
        return false;
    }

    void updateStatePriority(State<T> *current) {
        auto item = closedList.find(current);
        if (item != closedList.end()) {
            if (openList.CompareCost(current, item)) {
                closedList.erase(item);
                closedList.insert(current);
            }
        }
    }

public:

    PriorityBasedSearcher() : evaluatedNodes(0) {};

    virtual solution search(ISearchable<T> *searchable) = 0;

    virtual unsigned long getNumberOfNodesEvaluated() {
        return evaluatedNodes;
    }
};


#endif //PROJ2_PRIORITYBASEDSEARCHER_H
