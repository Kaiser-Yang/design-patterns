#ifndef DESIGN_PATTERNS_REDHEAD_DUCK_H
#define DESIGN_PATTERNS_REDHEAD_DUCK_H

#include <iostream>

#include "duck/duck.h"
#include "fly_behavior/fly_with_wings.h"
#include "quack_behavior/quack.h"

class RedheadDuck : public Duck {
public:
    RedheadDuck() {
        setFlyBehavior(std::make_unique<FlyWithWings>());
        setQuackBehavior(std::make_unique<Quack>());
    }

    void display() override { std::cout << "I'm a redhead duck.\n"; }
};

#endif
