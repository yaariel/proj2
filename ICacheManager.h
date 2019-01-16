//
// Created by frieddv on 1/5/19.
//

#ifndef PROJ2_ICACHEMANAGER_H
#define PROJ2_ICACHEMANAGER_H

template <class Problem, class Solution>

class ICacheManager {
public:
    virtual bool isSolutionSaved(Problem p) = 0;
    virtual Solution getSolution(Problem p) = 0;
    virtual void saveSolution(Problem p, Solution s) = 0;

    virtual ~ICacheManager() {}
};


#endif //PROJ2_ICACHEMANAGER_H
