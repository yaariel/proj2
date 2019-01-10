//
// Created by frieddv on 1/10/19.
//

#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H

template <class T>

class State {
    T current;
    double cost;
    State<T> *father;

public:

    State(T current, double cost, State<T> *father) : current(current), cost(cost), father(father) {};

    void setCost(double newCost) {cost = newCost;}

    void setFather(State<T> *newFather) {father = newFather;}

    double getCost() {return cost;}

    T getState() {return current;}

    State<T> *getFather() {return *father;}

    bool operator==(State<T> another) {return (bool) current == another.current;}
};


#endif //PROJ2_STATE_H
