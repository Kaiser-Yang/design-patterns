#ifndef DESIGN_PATTERN_STATE_H
#define DESIGN_PATTERN_STATE_H

#include <memory>

class GumballMachine;

class State {
public:
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;
protected:
    std::shared_ptr<GumballMachine> gumballMachine;
};

#endif
