//
// Created by frieddv on 1/6/19.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H

#define CACHE_DELIMITER '$'

#include "ICacheManager.h"
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

//might changing to generics instead of strings, and having a converter so we could have the string's functionality
class FileCacheManager : public ICacheManager<string, string> {

private:

    unordered_map<string, string> records;
    string path;
    pthread_mutex_t mutex;

    void loadFromFile();

    void saveToFile();

public:

    FileCacheManager(const string &path): path(path) { loadFromFile(); }

    virtual bool isSolutionSaved(string problem) {
        unsigned long count;
        pthread_mutex_lock(&mutex);
        count = records.count(problem);
        pthread_mutex_unlock(&mutex);
        return (bool)count;
    }

    virtual string getSolution(string problem) {
        return records[problem];
    }

    virtual void saveSolution(string problem, string solution) {
        records[problem] = solution;
    }

    virtual ~FileCacheManager() {saveToFile(); pthread_mutex_destroy(&mutex);}

};

#endif //PROJ2_FILECACHEMANAGER_H
