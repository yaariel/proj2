//
// Created by frieddv on 1/13/19.
//

#ifndef PROJ2_QUEUEBASEDSEARCHER_H
#define PROJ2_QUEUEBASEDSEARCHER_H

#include "ISearcher.h"
#include <queue>
#include <unordered_set>

template <class solution, class T>

class QueueBasedSearcher : public ISearcher<solution, T> {
private:

    unsigned long evaluatedNodes;

protected:
    std::queue<State<T>*> openList;
    std::unordered_set<State<T>*> closedList;

    State<T> *popOpenList() {
        ++evaluatedNodes;
        State<T> *result = openList.front();
        openList.pop();
        return result;
    }

    std::queue<State<T>*> backTrace(State<T> *current, ISearchable<T> *searchable) {
        std::queue<State<T> *> trace;
        State<T> *tempState = current;

        while (!(*tempState == searchable->getInitialState())) {
            trace.push_front(tempState);
            tempState = tempState->getFather();
        }
        trace.push_front(searchable->getInitialState());
        return trace;
    }

    unsigned long getOpenListSize() {
        return openList.size();
    }

    void addToOpenList(State<T> *current) {
        openList.push(current);
    }

    void addToCloseList(State<T> *current) {
        closedList.insert(current);
    }

    bool isInClosedList(State<T> *current) {
        for (auto node : closedList) {
            if (*current == *node) {
                return true;
            }
        }
        return false;
    }

    bool isInOpenList(State<T> *current) {
        std::vector<State<T>*> temp;
        while (!openList.empty()) {
            temp.push_back(openList.front());
            openList.pop();
        }
        for (auto item : temp) {
            openList.push(item);
        }
        for (auto item : temp) {
            if (*current == *item) {
                return true;
            }
        }
        return false;
    }

};


#endif //PROJ2_QUEUEBASEDSEARCHER_H
