#ifndef DESIGN_PATTERN_HAS_QUARTER_STATE_H
#define DESIGN_PATTERN_HAS_QUARTER_STATE_H

#include <memory>
#include <iostream>

#include "state.h"
#include "gumball_machine.h"

class HasQuarterState : public State {
public:
    HasQuarterState(std::shared_ptr<GumballMachine> gumballMachine) {
        this->gumballMachine = gumballMachine;
    }
    void insertQuarter() override {
        std::cout << "You can't insert another quarter\n";
    }
    void ejectQuarter() override {
        std::cout << "Quarter returned\n";
        gumballMachine->setState(gumballMachine->getNoQuarterState());
    }
    void turnCrank() override {
        std::cout << "You turned...\n";
        int winner = rand() % 10;
        if ((winner == 0) && (gumballMachine->getCount() > 1)) {
            gumballMachine->setState(gumballMachine->getWinnerState());
        } else {
            gumballMachine->setState(gumballMachine->getSoldState());
        }
    }
    void dispense() override {
        std::cout << "No gumball dispensed\n";
    }
};

#endif
