//
// Created by frieddv on 1/10/19.
//

#include "MyMatrixSearchable.h"

vector<State<pair<int, int>>> MyMatrixSearchable::getPossibleNextStates(State<pair<int, int>> &current) {
    vector<State<pair<int, int>>> result;
    int i = current.getState().first;
    int j = current.getState().second;
    if (i > 0) {
        result.push_back(State<pair<int,int>>(std::make_pair(i - 1, j), matrixStates[i-1][j], &current, UP));
    }
    if (i < width) {
        result.push_back(State<pair<int,int>>(std::make_pair(i + 1, j), matrixStates[i+1][j], &current, DOWN));
    }
    if (j > 0) {
        result.push_back(State<pair<int,int>>(std::make_pair(i, j - 1), matrixStates[i][j-1], &current, LEFT));
    }
    if (j < length) {
        result.push_back(State<pair<int,int>>(std::make_pair(i, j + 1), matrixStates[i][j+1], &current, RIGHT));
    }
    return result;
}
