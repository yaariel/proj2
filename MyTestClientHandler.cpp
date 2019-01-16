//
// Created by frieddv on 1/6/19.
//
#define BUFFER_SIZE 1024
#define END_OF_COMMUNICATION "end"
#define DELIMITER '\n'

#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sstream>
#include <algorithm>
#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int socket) {

    //enter into string the info from the socket
    vector<string> problem;
    string currentProblem = "";
    string temp = "";
    string solution;
    char buffer[BUFFER_SIZE] = {0};

    while (true)
    {
        ssize_t numBytesRead = recv(socket, buffer, BUFFER_SIZE, 0);

        if (numBytesRead > 0) {
            string check = buffer;
            stringstream ss(check);
            ssize_t lineAmount = count(check.begin(), check.end(), DELIMITER);
            for (ssize_t i = 0; i < lineAmount; ++i) {
                getline(ss, currentProblem, DELIMITER);
                if (!temp.empty()) {
                    temp += currentProblem;
                    currentProblem = temp;
                    temp = "";
                }
                if (currentProblem == END_OF_COMMUNICATION) {
                    if (cacheManager->isSolutionSaved(problem)) {
                        solution = cacheManager->getSolution(problem);
                    }
                    else {
                        solution = solver->solve(problem);
                        cacheManager->saveSolution(problem, solution);
                    }
                    write(socket, solution.c_str(), solution.length());
                    close(socket);
                    return;
                }
                problem.push_back(currentProblem);
            }
            //if we have half a line, save it, otherwise clear it
            if (!getline(ss, temp, DELIMITER))
                temp = "";
        }
    }


}

MyTestClientHandler::~MyTestClientHandler() {
    delete(cacheManager);
    delete(solver);

}
