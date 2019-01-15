//
// Created by ariel on 1/15/19.
//

#include <cerrno>
#include "MyParallelServer.h"

void *server_side::MyParallelServer::handleClient(void *args) {
    ClientHandlerArgs *handlerArgs = (ClientHandlerArgs *)args;
    handlerArgs->handler->handleClient(handlerArgs->socket);
    delete handlerArgs;
    return nullptr;
}

void server_side::MyParallelServer::run(int socket, bool *shouldStop, IClientHandler *handler) {
    int socketfd, addrLen;
    vector<pthread_t> threads;
    struct sockaddr_in srv_addr, clnt_addr;
    timeval timeout;
    ClientHandlerArgs *args;

    listen(socket, SOMAXCONN);
    addrLen = sizeof(clnt_addr);

    while (true) {


        socketfd = accept(socket, (struct sockaddr *)&clnt_addr, (socklen_t *)&addrLen);
        if (socketfd < 0) {
            if (*shouldStop)
                break;
            if (errno == EWOULDBLOCK)
                continue;
            perror("error accepting client\n");
            exit(1);
        }
        args = new ClientHandlerArgs();
        args->socket = socketfd;
        args->handler = handler;
        pthread_t thread;
        pthread_create(&thread, nullptr, handleClient, args);
        threads.push_back(thread);

        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
        setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    }

    for (pthread_t thread : threads) {
        pthread_join(thread, nullptr);
    }
}
