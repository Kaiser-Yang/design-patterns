#ifndef DESIGN_PATTERNS_SQUEAK_H
#define DESIGN_PATTERNS_SQUEAK_H

#include <iostream>

#include "quack_behavior.h"

class Squeak : public QuackBehavior {
public:
    void quack() override { std::cout << "I'm squeaking.\n"; }
};

#endif
