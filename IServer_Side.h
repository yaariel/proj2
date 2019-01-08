//
// Created by frieddv on 1/5/19.
//

#ifndef PROJ2_ISERVER_SIDE_H
#define PROJ2_ISERVER_SIDE_H

#include "IClientHandler.h"


namespace IServer_Side {
    class IServer {
    public:
        virtual void open(int port, IClientHandler handler) = 0;
        virtual void stop() = 0;
    };
}


#endif //PROJ2_ISERVER_SIDE_H
