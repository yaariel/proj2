//
// Created by frieddv on 1/6/19.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H

#include "ICacheManager.h"
#include <fstream>
#include <unordered_map>

using namespace std;


class FileCacheManager : public ICacheManager <string, string>{

private:

    unordered_map<string, string> records;
    string path;

    void loadFromFile();

    void saveToFile();

public:

    FileCacheManager(const string &path): path(path) { loadFromFile();}

    virtual bool isSolutionSaved(string problem) {
        return (bool) (records.count(problem));
    }

    virtual string getSolution(string problem) {
        return records[problem];
    }

    virtual void saveSolution(string solution, string problem) {
        records[problem] = solution;
    }

    virtual ~FileCacheManager();

};

#endif //PROJ2_FILECACHEMANAGER_H
