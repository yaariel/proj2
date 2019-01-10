//
// Created by frieddv on 1/6/19.
//
#define BUFFER_SIZE 1024
#define END_OF_COMMUNICATION "end"

#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>
#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int socket) {

    //enter into string the info from the socket
    string problem = "";
    string solution;
    char buffer[BUFFER_SIZE] = {0};

    while (true)
    {
        int numBytesRead = recv(socket, buffer, BUFFER_SIZE, 0);

        if (numBytesRead > 0) {
            string check = buffer;
            unsigned long newlineIndex = check.find('\n');
            if (newlineIndex != string::npos) {
                problem += check.substr(0, newlineIndex);
                check = check.substr(newlineIndex + 1);
                if (problem.length() > 0) {

                    if (!problem.compare(END_OF_COMMUNICATION)) {
                        close(socket);
                        return;
                    }
                    if (cacheManager->isSolutionSaved(problem)) {
                        //enter the solution to solution for returning to client
                        solution = cacheManager->getSolution(problem);
                    } else {
                        //enter the solution from solver to string
                        solution = solver->solve(problem);
                        cacheManager->saveSolution(problem, solution);
                    }

                    ssize_t n;

                    //send the message throw socket
                    n = write(socket, solution.c_str(), solution.length());

                    //if writing didn't work
                    if (n < 0) {
                        close(socket);
                        return;
                    }

                    //if check still has data, save it to next run and reset check
                    if (check.length() > 0) {
                        problem = check;
                        check = "";
                    }
                    //else, reset problem
                    else {
                        problem = "";
                    }
                }

            }
            //add the 'remainder' to problem for next run
            if (check.length() > 0)
                problem += check;
        }
    }


}
