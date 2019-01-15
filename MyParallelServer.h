//
// Created by ariel on 1/15/19.
//

#ifndef PROJ2_MYPARALLELSERVER_H
#define PROJ2_MYPARALLELSERVER_H

#include "TCPServer.h"

namespace server_side {
    class MyParallelServer : public TCPServer {
    private:
        static void* handleClient(void *args);

    protected:
        virtual void run(int socket, bool *shouldStop, IClientHandler *handler);
    };

    typedef struct {
        int socket;
        IClientHandler *handler;
    } ClientHandlerArgs;
}


#endif //PROJ2_MYPARALLELSERVER_H
