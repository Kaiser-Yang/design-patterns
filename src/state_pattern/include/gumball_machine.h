#ifndef DESIGN_PATTERN_GUMBALL_MACHINE_H
#define DESIGN_PATTERN_GUMBALL_MACHINE_H

#include <memory>
#include <iostream>

#include "state/state.h"

class GumballMachine : public std::enable_shared_from_this<GumballMachine> {
public:
    GumballMachine(size_t numberGumballs) : numberGumballs(numberGumballs) {}
    void init();
    void insertQuarter() {
        state->insertQuarter();
    }
    void ejectQuarter() {
        state->ejectQuarter();
    }
    void turnCrank() {
        state->turnCrank();
        state->dispense();
    }
    void setState(std::shared_ptr<State> state) {
        this->state = state;
    }
    void releaseBall() {
        std::cout << "A gumball comes rolling out the slot...\n";
        if (numberGumballs != 0) {
            --numberGumballs;
        }
    }
    int getCount() {
        return numberGumballs;
    }
    void refill(int count) {
        numberGumballs = count;
        state = getNoQuarterState();
    }
    std::shared_ptr<State> getSoldOutState() {
        return soldOutState;
    }
    std::shared_ptr<State> getNoQuarterState() {
        return noQuarterState;
    }
    std::shared_ptr<State> getHasQuarterState() {
        return hasQuarterState;
    }
    std::shared_ptr<State> getSoldState() {
        return soldState;
    }
    std::shared_ptr<State> getWinnerState() {
        return winnerState;
    }

    std::shared_ptr<State> getState() { return state; }
private:
    size_t numberGumballs;
    std::shared_ptr<State> state;
    std::shared_ptr<State> soldOutState;
    std::shared_ptr<State> noQuarterState;
    std::shared_ptr<State> hasQuarterState;
    std::shared_ptr<State> soldState;
    std::shared_ptr<State> winnerState;
};

#endif
