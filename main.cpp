#include <iostream>
#include <regex>
#include <chrono>
#include <thread>
#include "MyParallelServer.h"
#include "MyTestClientHandler.h"
#include "SearcherSolver.h"
#include "FileCacheManager.h"

int main(int argc, char *argv[]) {
    if (argc != 2 || !regex_match(argv[1], regex("^\\d+")))
        throw invalid_argument("invalid arguments to main");
    server_side::IServer *server = new server_side::MyParallelServer();
    server->open(stoi(argv[1]), new MyTestClientHandler(new SearcherSolver(), new FileCacheManager("cache.txt")));
    this_thread::sleep_for(chrono::seconds(100));
    server->stop();
    delete server;
    return 0;
}