//
// Created by frieddv on 1/15/19.
//

#ifndef PROJ2_SEARCHERSOLVER_H
#define PROJ2_SEARCHERSOLVER_H


#include "ISolver.h"
#include "MyMatrixSearchable.h"
#include "SearchableMatrixFactory.h"
#include "ISearcher.h"
#include "AStarSearcher.h"
#include <vector>
#include <string>

using namespace std;

class SearcherSolver : public ISolver<string, string> {
public:

    virtual string solve(string problem) {
        MyMatrixSearchable matrixProblem = SearchableMatrixFactory::createMatrix(problem);
        //todo: need to change it to vector of pair<int, int> instead of string as solution
        //todo: maybe changing the return value of matrixProblem to vector of states instead of string
        ISearcher<string, pair<int, int>> *bestFS = new AStarSearcher<string, pair<int, int>>();
        return bestFS->search(&matrixProblem);
    }
};

#endif //PROJ2_SEARCHERSOLVER_H
