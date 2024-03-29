//
// Created by frieddv on 1/13/19.
//

#ifndef PROJ2_QUEUEBASEDSEARCHER_H
#define PROJ2_QUEUEBASEDSEARCHER_H

#include "ISearcher.h"
#include <queue>
#include <unordered_set>
#include <stack>

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

    string backTrace(State<T> *current, ISearchable<T> *searchable) {
        stack<State<T> *> trace;
        State<T> *tempState = current;
        string result = "";

        while (!(*tempState == *searchable->getInitialState())) {
            trace.push(tempState);
            tempState = tempState->getFather();
        }
        trace.push(searchable->getInitialState());

        while (!trace.empty()) {
            switch (trace.top()->getDirection()) {
                case UP:
                    result += "up,";
                    break;
                case DOWN:
                    result += "down,";
                    break;
                case LEFT:
                    result += "left,";
                    break;
                case RIGHT:
                    result += "right,";
                    break;
                default:
                    break;
            }
            trace.pop();
        }
        result.pop_back();
        return result;
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

    void deleteEverything() {
        while (!openList.empty()) {
            auto item = openList.front();
            openList.pop();
            delete item;
        }
        closedList.clear();
    }


public:

    QueueBasedSearcher() : evaluatedNodes(0) {};

    virtual solution search(ISearchable<T> *searchable) = 0;

    virtual unsigned long getNumberOfNodesEvaluated() {
        return evaluatedNodes;
    }

};


#endif //PROJ2_QUEUEBASEDSEARCHER_H
