#ifndef DESIGN_PATTERN_NO_QUARTER_STATE_H
#define DESIGN_PATTERN_NO_QUARTER_STATE_H

#include <memory>
#include <iostream>

#include "state.h"
#include "gumball_machine.h"

class NoQuarterState : public State {
public:
    NoQuarterState(std::shared_ptr<GumballMachine> gumballMachine) {
        this->gumballMachine = gumballMachine;
    }
    void insertQuarter() override {
        std::cout << "You inserted a quarter\n";
        gumballMachine->setState(gumballMachine->getHasQuarterState());}
    void ejectQuarter() override {
        std::cout << "You haven't inserted a quarter\n";
    }
    void turnCrank() override {
        std::cout << "You turned, but there's no quarter\n";
    }
    void dispense() override {
        std::cout << "You need to pay first\n";}
};

#endif
