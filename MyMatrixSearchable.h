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

    MyMatrixSearchable(const vector<vector<int>> &matrix, State<pair<int, int>> &initState,
                       State<pair<int, int>> &goalState) :matrixStates(matrix), initState(initState), goalState(goalState) {
        width = matrixStates[0].size();
        length = matrixStates.size();
    }

    virtual State<pair<int, int>> getInitialState() {
        return initState;
    }

    vector<vector<int>> matrixCreator(vector<string> toMatrix) {
        implement this!
    }

    virtual State<pair<int, int>> getGoalState() {
        return goalState;
    }

    virtual vector<State<pair<int, int>>> getPossibleNextStates(State<pair<int, int>> &current);


};


#endif //PROJ2_MYMATRIXPROBLEM_H
