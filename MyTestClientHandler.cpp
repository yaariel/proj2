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
    string problem = "";
    string currentLine = "";
    string previousLine = "";
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
                getline(ss, currentLine, DELIMITER);
                if (!previousLine.empty()) {
                    previousLine += currentLine;
                    currentLine = previousLine;
                    previousLine = "";
                }
                if (currentLine == END_OF_COMMUNICATION) {
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
                problem += currentLine + DELIMITER;
            }
            //if we have half a line, save it
            if (getline(ss, currentLine, DELIMITER))
                previousLine += currentLine;
        }
    }


}

MyTestClientHandler::~MyTestClientHandler() {
    delete cacheManager;
    delete solver;

}
