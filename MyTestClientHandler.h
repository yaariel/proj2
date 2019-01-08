//
// Created by frieddv on 1/6/19.
//

#ifndef PROJ2_MYTESTCLIENTHANDLER_H
#define PROJ2_MYTESTCLIENTHANDLER_H


#include <string>
#include "IClientHandler.h"
#include "ISolver.h"
#include "ICacheManager.h"

class MyTestClientHandler : public IClientHandler{
public:
    virtual void handleClient(int socket);

private:
    ISolver<string, string> *solver;
    ICacheManager<string, string> *cacheManager;
};


#endif //PROJ2_MYTESTCLIENTHANDLER_H
