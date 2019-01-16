//
// Created by frieddv on 1/13/19.
//

#ifndef PROJ2_STACKBASEDSEARCHER_H
#define PROJ2_STACKBASEDSEARCHER_H

#include "ISearcher.h"
#include <stack>
#include <unordered_set>
#include <queue>


template <class solution, class T>

class StackBasedSearcher : public ISearcher<solution, T> {
private:

    unsigned long evaluatedNodes;

protected:

    std::stack<State<T>*> openList;
    std::unordered_set<State<T>*> closedList;

    State<T> *popOpenList() {
        ++evaluatedNodes;
        State<T> *result = openList.top();
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

    bool isInOpenList(State<T> *current) {
        bool isFound = false;
        std::stack<State<T>*> temp;
        while (!openList.empty()) {
            if (openList.top() == *current) {
                isFound = true;
                break;
            }
            temp.push(openList.top());
            openList.pop();
        }
        while (!temp.empty()) {
            openList.push(temp.top());
            temp.pop();
        }
        return isFound;
    }

    bool isInClosedList(State<T> *current) {
        for (auto node : closedList) {
            if (*current == *node) {
                return true;
            }
        }
        return false;
    }
};


#endif //PROJ2_STACKBASEDSEARCHER_H
