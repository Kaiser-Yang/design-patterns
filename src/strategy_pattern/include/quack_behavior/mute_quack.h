#ifndef DESIGN_PATTERNS_MUTE_QUACK_H
#define DESIGN_PATTERNS_MUTE_QUACK_H

#include <iostream>

#include "quack_behavior.h"

class MuteQuack : public QuackBehavior {
public:
    void quack() override { std::cout << "I'm muted.\n"; }
};

#endif
