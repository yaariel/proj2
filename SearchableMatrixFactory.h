//
// Created by frieddv on 1/13/19.
//

#ifndef PROJ2_SEARCHABLEMATRIXFACTORY_H
#define PROJ2_SEARCHABLEMATRIXFACTORY_H

#define DELIMITER ','

#include "MyMatrixSearchable.h"

class SearchableMatrixFactory {
public:
    static MyMatrixSearchable createMatrix(vector<string> input);

private:
    static string extractLastLine(vector<string> &input);

    static vector<int> parseRow(const string &line);

    static pair<int, int> parseCoordinates(const string &data);
};


#endif //PROJ2_SEARCHABLEMATRIXFACTORY_H
