//
// Created by frieddv on 1/5/19.
//

#ifndef PROJ2_ISOLVER_H
#define PROJ2_ISOLVER_H

template <class Problem, class Solution>
class ISolver {
public:
    virtual Solution solve(Problem problem) = 0;
};


#endif //PROJ2_ISOLVER_H
