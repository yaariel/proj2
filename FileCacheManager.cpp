//
// Created by frieddv on 1/8/19.
//

#include <sstream>
#include "FileCacheManager.h"


void FileCacheManager::loadFromFile() {
    ifstream input(path);
    if (!(input.is_open())) {
        return;
    }
    string buffer;
    while (getline(input, buffer)) {
        unsigned long delimiter = buffer.find_last_of(CACHE_DELIMITER);
        string problem = buffer.substr(0, delimiter);
        string solution = buffer.substr(delimiter + 1, buffer.size() - delimiter);
        records[parseProblem(problem)] = solution;
    }
    input.close();
}

void FileCacheManager::saveToFile() {
    ofstream writer(path);
    if (!(writer.is_open())) {
        throw "error in opening file";
    }
    //write into file the keys with '$' as delimiter between the problem
    for (auto key : records) {
        for (string line : key.first)
            writer << line << CACHE_DELIMITER;
        writer << CACHE_DELIMITER << key.second << endl;
    }
    writer.close();
}

vector<string> FileCacheManager::parseProblem(string problem) {
    vector<string> parsedProblem;
    string line;
    stringstream ss(problem);
    while (getline(ss, line, CACHE_DELIMITER)) {
        parsedProblem.push_back(line);
    }
    return parsedProblem;
}
