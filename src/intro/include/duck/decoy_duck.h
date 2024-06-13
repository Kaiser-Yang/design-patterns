#ifndef DESIGN_PATTERNS_DECOY_DUCK_H
#define DESIGN_PATTERNS_DECOY_DUCK_H

#include <iostream>

#include "duck/duck.h"
#include "fly_behavior/fly_no_way.h"
#include "quack_behavior/mute_quack.h"

class DecoyDuck : public Duck {
public:
    DecoyDuck() {
        setFlyBehavior(std::make_unique<FlyNoWay>());
        setQuackBehavior(std::make_unique<MuteQuack>());
    }

    void display() override { std::cout << "I'm a decoy duck.\n"; }
};

#endif
