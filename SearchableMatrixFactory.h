//
// Created by frieddv on 1/13/19.
//

#ifndef PROJ2_SEARCHABLEMATRIXFACTORY_H
#define PROJ2_SEARCHABLEMATRIXFACTORY_H

#define DELIMITER ','

#include "MyMatrixSearchable.h"

class SearchableMatrixFactory {
public:
    MyMatrixSearchable createMatrix(vector<string> input) const;

private:
    string extractLastLine(vector<string> &input) const;

    vector<int> parseRow(const string &line) const;

    pair<int, int> parseCoordinates(const string &data) const;
};


#endif //PROJ2_SEARCHABLEMATRIXFACTORY_H
