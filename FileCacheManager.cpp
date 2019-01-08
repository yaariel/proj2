//
// Created by frieddv on 1/8/19.
//

#include "FileCacheManager.h"


void FileCacheManager::loadFromFile() {
    ifstream input(path);
    if (!(input.is_open())) {
        return;
    }
    string buffer;
    while (getline(input, buffer)) {
        unsigned long delimiter = buffer.find('$');
        string splitProblem = buffer.substr(0, delimiter);
        string splitSolution = buffer.substr(delimiter + 1, buffer.size() - delimiter);
        records[splitProblem] = splitSolution;
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
        writer << key.first << '$' << key.second << endl;
    }
    writer.close();
}
