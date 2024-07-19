#ifndef DESIGN_PATTERN_WINNER_STATE_H
#define DESIGN_PATTERN_WINNER_STATE_H

#include <memory>
#include <iostream>

#include "state.h"
#include "gumball_machine.h"

class WinnerState : public State {
public:
    WinnerState(std::shared_ptr<GumballMachine> gumballMachine) {
        this->gumballMachine = gumballMachine;
    }
    void insertQuarter() override {
        std::cout << "Please wait, we're already giving you a gumball\n";
    }
    void ejectQuarter() override {
        std::cout << "Sorry, you already turned the crank\n";
    }
    void turnCrank() override {
        std::cout << "Turning twice doesn't get you another gumball\n";
    }
    void dispense() override {
        gumballMachine->releaseBall();
        if (gumballMachine->getCount() == 0) {
            std::cout << "Oops, out of gumballs!\n";
            gumballMachine->setState(gumballMachine->getSoldOutState());
        } else {
            gumballMachine->releaseBall();
            std::cout << "YOU'RE A WINNER! You get two gumballs for your quarter\n";
            if (gumballMachine->getCount() > 0) {
                gumballMachine->setState(gumballMachine->getNoQuarterState());
            } else {
                std::cout << "Oops, out of gumballs!\n";
                gumballMachine->setState(gumballMachine->getSoldOutState());
            }
        }
    }
};

#endif
