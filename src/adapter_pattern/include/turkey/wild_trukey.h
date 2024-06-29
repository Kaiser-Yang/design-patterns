#ifndef DESING_PATTERNS_WILD_TURKEY_H
#define DESING_PATTERNS_WILD_TURKEY_H

#include <iostream>

#include "turkey.h"

class WildTurkey : public Turkey {
public:
    void gobble() override { std::cout << "Gobble gobble" << std::endl; }
    void fly() override { std::cout << "I'm flying a short distance" << std::endl; }
};

#endif
