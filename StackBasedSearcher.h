//
// Created by frieddv on 1/13/19.
//

#ifndef PROJ2_STACKBASEDSEARCHER_H
#define PROJ2_STACKBASEDSEARCHER_H

#include "ISearcher.h"
#include <stack>
#include <unordered_set>
#include <queue>

using namespace std;

template <class solution, class T>

class StackBasedSearcher : public ISearcher<solution, T> {
private:

    unsigned long evaluatedNodes;

protected:

    stack<State<T>*> openList;
    unordered_set<State<T>*> closedList;

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
                    result += "Up,";
                    break;
                case DOWN:
                    result += "Down,";
                    break;
                case LEFT:
                    result += "Left,";
                    break;
                case RIGHT:
                    result += "Right,";
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
