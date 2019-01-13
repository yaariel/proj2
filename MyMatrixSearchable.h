//
// Created by frieddv on 1/10/19.
//

#ifndef PROJ2_MYMATRIXPROBLEM_H
#define PROJ2_MYMATRIXPROBLEM_H


#include <string>
#include "ISearchable.h"
using namespace std;

class MyMatrixSearchable: public ISearchable<pair<int, int>> {

    vector<vector<int>> matrixStates;
    unsigned long length;
    unsigned long width;
    State<pair<int, int>> initState;
    State<pair<int, int>> goalState;

public:

    MyMatrixSearchable(const vector<string> &matrix, State<pair<int, int>> &initState,
                       State<pair<int, int>> &goalState) : length(length), width(width),
                                                          initState(initState), goalState(goalState) {
        matrixStates = matrixCreator(matrix);
        width = matrixStates[0].size();
        length = matrixStates.size();

    }

    virtual State<pair<int, int>> getInitialState();

    vector<vector<int>> matrixCreator(vector<string> toMatrix) {

    }

    virtual bool isGoalState(State<pair<int, int>> &current) {
        return current == goalState;
    }

    virtual vector<State<pair<int, int>>> getAllPossibleStates(State<pair<int, int>> &current) {

    }
};


#endif //PROJ2_MYMATRIXPROBLEM_H
