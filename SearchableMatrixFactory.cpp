//
// Created by frieddv on 1/13/19.
//

#include <sstream>
#include "SearchableMatrixFactory.h"

MyMatrixSearchable SearchableMatrixFactory::createMatrix(vector<string> input) const {
    vector<vector<int>> matrix;
    //keeping the init and goal states separately, for convenience
    string goalData = extractLastLine(input);
    string initData = extractLastLine(input);
    //allocate space for the rows in advance, for efficiency
    matrix.reserve(input.size());
    for (const auto &line : input) {
        matrix.push_back(parseRow(line));
    }
    pair<int, int> initPair = parseCoordinates(initData);
    double costInit = matrix[initPair.first][initPair.second];
    pair<int, int> goalPair = parseCoordinates(goalData);
    double costGoal = matrix[goalPair.first][goalPair.second];
    State<pair<int, int>> init = State<pair<int,int>>(initPair, costInit, NULL, NOT);
    State<pair<int, int>> goal = State<pair<int,int>>(goalPair, costGoal, NULL, NOT);
    return MyMatrixSearchable(matrix, init, goal);
}

vector<int> SearchableMatrixFactory::parseRow(const string &line) const {
    vector<int> lineAsInt;
    string token;
    stringstream ss(line);
    while (getline(ss, token, DELIMITER)) {
        lineAsInt.push_back(stoi(token));
    }
    return lineAsInt;
}

string SearchableMatrixFactory::extractLastLine(vector<string> &input) const {
    string temp = input.back();
    input.pop_back();
    return temp;
}

pair<int, int> SearchableMatrixFactory::parseCoordinates(const string &data) const {
    string coordinate;
    int first, second;
    stringstream ss(data);
    getline(ss, coordinate, DELIMITER);
    first = stoi(coordinate);
    getline(ss, coordinate);
    second = stoi(coordinate);
    return make_pair(first, second);
}
