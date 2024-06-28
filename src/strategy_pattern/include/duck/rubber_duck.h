#ifndef DESIGN_PATTERNS_RUBBER_DUCK_H
#define DESIGN_PATTERNS_RUBBER_DUCK_H

#include <iostream>

#include "duck/duck.h"
#include "fly_behavior/fly_no_way.h"
#include "quack_behavior/squeak.h"

class RubberDuck : public Duck {
public:
    RubberDuck() {
        setFlyBehavior(std::make_unique<FlyNoWay>());
        setQuackBehavior(std::make_unique<Squeak>());
    }

    void display() override { std::cout << "I'm a rubber duck.\n"; }
};

#endif
