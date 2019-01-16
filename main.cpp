#include <iostream>
#include <regex>
#include <chrono>
#include <thread>
#include "MyParallelServer.h"
#include "MyTestClientHandler.h"
#include "SearcherSolver.h"
#include "FileCacheManager.h"

bool isNumber(string arg) {
    if (arg.empty())
        return false;
    for (char c : arg) {
        if (c < '0' || c > '9')
            return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2 || !isNumber(argv[1]))
        throw invalid_argument("invalid arguments to main");
    server_side::IServer *server = new server_side::MyParallelServer();
    server->open(stoi(argv[1]), new MyTestClientHandler((ISolver<string, string>*)new SearcherSolver(), (ICacheManager<string, string>*)new FileCacheManager("cache.txt")));
    this_thread::sleep_for(chrono::seconds(100));
    server->stop();
    delete server;
    return 0;
}