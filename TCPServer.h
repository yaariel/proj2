//
// Created by ariel on 1/15/19.
//

#ifndef PROJ2_TCPSERVER_H
#define PROJ2_TCPSERVER_H

#include <vector>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "IServer.h"

using namespace std;

namespace server_side {
    class TCPServer : public IServer {
    private:
        vector<pthread_t> threads;
        bool shouldStop = false;

        static void *acceptNewClient(void *args);

    protected:
        virtual void run(int socket, bool *shouldStop, IClientHandler *handler) = 0;

    public:
        void open(int port, IClientHandler *handler);

        void stop();
    };

    typedef struct {
        TCPServer *server;
        int port;
        bool *shouldStop;
        IClientHandler *handler;
    } TCPServerArgs;
}


#endif //PROJ2_TCPSERVER_H
