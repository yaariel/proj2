//
// Created by frieddv on 1/6/19.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H

#define DELIMITER '$'

#include "ICacheManager.h"
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

//might changing to generics instead of strings, and having a converter so we could have the string's functionality
class FileCacheManager : public ICacheManager<vector<string>, string> {

private:

    unordered_map<vector<string>, string> records;
    string path;

    void loadFromFile();

    void saveToFile();

    vector<string> parseProblem(string problem);

public:

    FileCacheManager(const string &path): path(path) { loadFromFile(); }

    virtual bool isSolutionSaved(vector<string> problem) {
        return (bool) (records.count(problem));
    }

    virtual string getSolution(vector<string> problem) {
        return records[problem];
    }

    virtual void saveSolution(vector<string> problem, string solution) {
        records[problem] = solution;
    }

    virtual ~FileCacheManager() {saveToFile();}

};

#endif //PROJ2_FILECACHEMANAGER_H
