#ifndef DESIGN_PATTERN_SOLD_OUT_STATE_H
#define DESIGN_PATTERN_SOLD_OUT_STATE_H

#include <memory>
#include <iostream>

#include "state.h"
#include "gumball_machine.h"

class SoldOutState : public State {
public:
    SoldOutState(std::shared_ptr<GumballMachine> gumballMachine) {
        this->gumballMachine = gumballMachine;
    }
    void insertQuarter() override {
        std::cout << "You can't insert a quarter, the machine is sold out\n";
    }
    void ejectQuarter() override {
        std::cout << "You can't eject, you haven't inserted a quarter yet\n";
    }
    void turnCrank() override {
        std::cout << "You turned, but there are no gumballs\n";
    }
    void dispense() override {
        std::cout << "No gumball dispensed\n";
    }
};

#endif
