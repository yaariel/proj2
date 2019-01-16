//
// Created by frieddv on 1/6/19.
//

#ifndef PROJ2_MYTESTCLIENTHANDLER_H
#define PROJ2_MYTESTCLIENTHANDLER_H


#include <string>
#include <vector>
#include "IClientHandler.h"
#include "ISolver.h"
#include "ICacheManager.h"

class MyTestClientHandler : public IClientHandler{
public:
    virtual void handleClient(int socket);

    virtual ~MyTestClientHandler();

    MyTestClientHandler(ISolver<vector<string>, string> *solver, ICacheManager<vector<string>, string> *cacheManager) : solver(solver), cacheManager(cacheManager) {}

private:
    ISolver<vector<string>, string> *solver;
    ICacheManager<vector<string>, string> *cacheManager;
};


#endif //PROJ2_MYTESTCLIENTHANDLER_H
