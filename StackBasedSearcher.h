//
// Created by frieddv on 1/13/19.
//

#ifndef PROJ2_STACKBASEDSEARCHER_H
#define PROJ2_STACKBASEDSEARCHER_H

#include "ISearcher.h"
#include <stack>
#include <vector>
#include <queue>

using namespace std;

template <class solution, class T>

class StackBasedSearcher : public ISearcher<solution, T> {
private:

    unsigned long evaluatedNodes;

protected:

    stack<State<T>*> openList;
    vector<State<T>*> closedList;

    State<T> *popOpenList() {
        ++evaluatedNodes;
        State<T> *result = openList.top();
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

    bool isInOpenList(State<T> *current) {
        bool isFound = false;
        stack<State<T>*> temp;
        while (!openList.empty()) {
            if (*openList.top() == *current) {
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

    void deleteEverything() {
        while (!openList.empty()) {
            auto item = openList.top();
            openList.pop();
            delete item;
        }
        closedList.clear();
    }


public:

    StackBasedSearcher() : evaluatedNodes(0) {};

    virtual solution search(ISearchable<T> *searchable) = 0;

    virtual unsigned long getNumberOfNodesEvaluated() {
        return evaluatedNodes;
    }
};


#endif //PROJ2_STACKBASEDSEARCHER_H
