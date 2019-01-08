//
// Created by frieddv on 1/6/19.
//

#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int port) {




    if (cacheManager->isSolutionSaved()) {
        //write to socket the answer
    }
    else {
        //enter the solution from solver to string
        string solution = solver->solve();
        //
    }
}
