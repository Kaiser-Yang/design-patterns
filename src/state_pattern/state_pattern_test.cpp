#include <memory>

#include "gumball_machine.h"

void StatePatternTest() {
    std::shared_ptr<GumballMachine> gumballMachine = std::make_shared<GumballMachine>(5);

    gumballMachine->init();

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    gumballMachine->insertQuarter();
    gumballMachine->ejectQuarter();
    gumballMachine->turnCrank();

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->ejectQuarter();

    gumballMachine->insertQuarter();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
}

int main() {
    StatePatternTest();
    return 0;
}
