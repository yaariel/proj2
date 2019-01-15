//
// Created by frieddv on 1/13/19.
//

#ifndef PROJ2_QUEUEBASEDSEARCHER_H
#define PROJ2_QUEUEBASEDSEARCHER_H

#include "ISearcher.h"
#include <queue>

template <class solution, class T>

class QueueBasedSearcher : public ISearcher<solution, T> {
private:

    unsigned long evaluatedNodes;

protected:
    std::queue<State<T>*> openList;
    std::vector<State<T>*> closedList;

    State<T> *popOpenList() {
        ++evaluatedNodes;
        State<T> *result = openList.front();
        openList.pop();
        return result;
    }

    solution backTrace(State<T> *current, ISearchable<T> *searchable) {
        implement this!
    }

    unsigned long getOpenListSize() {
        return openList.size();
    }

    void addToOpenList(State<T> *current) {
        openList.push(current);
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
