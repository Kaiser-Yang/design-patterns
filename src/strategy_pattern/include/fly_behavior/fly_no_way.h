#ifndef DESIGN_PATTERNS_FLY_NO_WAY_H
#define DESIGN_PATTERNS_FLY_NO_WAY_H

#include <iostream>

#include "fly_behavior.h"

class FlyNoWay : public FlyBehavior {
public:
    void fly() override { std::cout << "I cannot fly.\n"; }
};

#endif
