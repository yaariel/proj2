//
// Created by frieddv on 1/11/19.
//

#ifndef PROJ2_PRIORITYBASEDSEARCHER_H
#define PROJ2_PRIORITYBASEDSEARCHER_H

#include "ISearcher.h"
#include "CompareCost.h"
#include "State.h"
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>

using namespace std;

template <class solution, class T>

class PriorityBasedSearcher : public ISearcher<solution, T> {
private:

    unsigned long evaluatedNodes;

protected:

    //maybe the member itself need to move into private section, depends on
    multiset<State<T>*, CompareCost<T>> openList;
    vector<State<T>*> closedList;

    State<T> *popOpenList() {
        ++evaluatedNodes;
        auto iter = openList.begin();
        State<T> *result = *iter;
        openList.erase(iter);
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
        bool wasFound = false;
        for (auto item : openList) {
            if (*item == *current) {
                wasFound = true;
                if (item->getCost() > current->getCost()) {
                    openList.erase(item);
                    delete item;
                    openList.insert(current);
                }
                break;
            }
        }
        if (!wasFound)
            openList.insert(current);
    }

    void deleteEverything() {
        openList.erase(openList.begin(), openList.end());
        for (auto item : closedList)
            delete item;
    }


public:

    PriorityBasedSearcher() : evaluatedNodes(0) {};

    virtual solution search(ISearchable<T> *searchable) = 0;

    virtual unsigned long getNumberOfNodesEvaluated() {
        return evaluatedNodes;
    }
};


#endif //PROJ2_PRIORITYBASEDSEARCHER_H
