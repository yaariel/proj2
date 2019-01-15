//
// Created by frieddv on 1/5/19.
//

#ifndef PROJ2_CLIENTHANDLER_H
#define PROJ2_CLIENTHANDLER_H

using namespace std;

class IClientHandler {
public:
    virtual void handleClient (int socket) = 0;

    virtual ~IClientHandler(){}
};


#endif //PROJ2_CLIENTHANDLER_H
