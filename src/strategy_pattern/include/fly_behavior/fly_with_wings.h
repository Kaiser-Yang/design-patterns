#ifndef DESIGN_PATTERNS_FLY_WITH_WINGS_H
#define DESIGN_PATTERNS_FLY_WITH_WINGS_H

#include <iostream>

#include "fly_behavior.h"

class FlyWithWings : public FlyBehavior {
public:
    void fly() override { std::cout << "I'm flying with wings.\n"; }
};

#endif
