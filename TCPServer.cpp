//
// Created by ariel on 1/15/19.
//

#include "TCPServer.h"

void server_side::TCPServer::open(int port, IClientHandler *handler) {
    TCPServerArgs *args = new TCPServerArgs();
    args->server = this;
    args->port = port;
    args->handler = handler;
    args->shouldStop = &shouldStop;
    pthread_t thread;
    pthread_create(&thread, nullptr, acceptNewClient, args);
    threads.push_back(thread);
}

void server_side::TCPServer::stop() {
    shouldStop = true;
    for (pthread_t thread : threads)
        pthread_join(thread, nullptr);
}

void *server_side::TCPServer::acceptNewClient(void *args) {
    TCPServerArgs *serverArgs = (TCPServerArgs *)args;
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in srv_addr, clnt_addr;
    if (socketfd < 0) {
        perror("error opening socket\n");
        exit(1);
    }

    bzero((char *)&srv_addr, sizeof(srv_addr));

    srv_addr.sin_family = AF_INET;
    srv_addr.sin_addr.s_addr = INADDR_ANY;
    srv_addr.sin_port = htons(serverArgs->port);

    if (bind(socketfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) < 0) {
        perror("error with binding\n");
        exit(1);
    }

    serverArgs->server->run(socketfd, serverArgs->shouldStop, serverArgs->handler);

    close(socketfd);
    delete serverArgs->handler;
    delete serverArgs;
    return nullptr;
}
