#ifndef DESIGN_PATTERNS_QUACK_H
#define DESIGN_PATTERNS_QUACK_H

#include <iostream>

#include "quack_behavior.h"

class Quack : public QuackBehavior {
public:
    void quack() override { std::cout << "I'm quacking.\n"; }
};

#endif
