//
// Created by frieddv on 1/5/19.
//

#ifndef PROJ2_CLIENTHANDLER_H
#define PROJ2_CLIENTHANDLER_H

using namespace std;

class IClientHandler {
public:
    virtual void handleClient (int port) = 0;
};


#endif //PROJ2_CLIENTHANDLER_H
