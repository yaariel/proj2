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

    solution backTrace(State<T> *current, ISearchable<T> *searchable) {
        std::queue<State<T> *> trace;
        std::queue<State<T> *> output;
        State<T> *tempState = current;

        while (!(*tempState == searchable->getInitialState())) {
            trace.push_front(tempState);
            tempState = tempState->getFather();
        }
        trace.push_front(searchable->getInitialState());

        return output;
    }

    unsigned long getOpenListSize() {
        return openList.size();
    }

    void addToOpenList(State<T> *current) {
        openList.push(current);
    }

    bool isInOpenList(State<T> *current) {
        std::vector<State<T>*> temp;
        while (!openList.empty()) {
            temp.push_back(openList.top());
            openList.pop();
        }

        //need to be reversed
        auto it = temp.rbegin();
        for (; it != temp.begin(); it++) {
            openList.push(*it);
        }
        for (auto item : temp) {
            if (*current == *item) {
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
};


#endif //PROJ2_STACKBASEDSEARCHER_H
