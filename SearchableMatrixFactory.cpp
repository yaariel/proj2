//
// Created by frieddv on 1/13/19.
//
#define DELIMETER_SIZE 1

#include "SearchableMatrixFactory.h"

MyMatrixSearchable SearchableMatrixFactory::createMatrix(vector<string> &input) {
    vector<vector<int>> matrix;
    size_t prev = 0, pos = 0;
    //keeping the init and goal state for making them
    string initData = input[input.size() - 2];
    string goalData = input[input.size() - 1];
    //extracting out to avoid for inserting to matrix the sinit and goal states
    matrix.pop_back();
    matrix.pop_back();
    for (auto line : input) {
        vector<int> lineAsInt;
        do {
            pos = line.find(",", prev);
            if (pos == string::npos)
                pos = line.length();
            string token = line.substr(prev, pos - prev);
            if (!token.empty())
                lineAsInt.push_back(stoi(token));
            prev = pos + DELIMETER_SIZE;
        } while (pos < line.length() && prev < line.length());
        matrix.push_back(lineAsInt);
    }
    size_t delimiterInit = initData.find(',');
    size_t delimiterGoal = goalData.find(',');
    string initSplitFirst = initData.substr(0, delimiterInit);
    string initSplitSecond = initData.substr(delimiterInit, initData.length());
    string goalSplitFirst = goalData.substr(0, delimiterGoal);
    std::pair<int, int> initPair = make_pair(stoi(initSplitFirst), stoi(initSplitSecond));
    double costInit = matrix[initPair.first] [initPair.second];
    string goalSplitSecond = goalData.substr(delimiterGoal, goalData.length());
    std::pair<int, int> goalPair = make_pair(stoi(goalSplitFirst), stoi(goalSplitSecond));
    double costGoal = matrix[goalPair.first] [goalPair.second];
    State<pair<int, int>> init = State<pair<int,int>>(initPair, costInit, NULL, NOT);
    State<pair<int, int>> goal = State<pair<int,int>>(goalPair, costGoal, NULL, NOT);
    return MyMatrixSearchable(matrix, init, goal);
}
