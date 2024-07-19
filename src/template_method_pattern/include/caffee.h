#ifndef DESIGN_PATTERNS_CAFFEE_H
#define DESIGN_PATTERNS_CAFFEE_H

#include "caffeine_beverage.h"

class Caffee : public CaffeineBeverage {
public:
    void brew() override { std::cout << "Dripping Coffee through filter" << std::endl; }
    void addCondiments() override { std::cout << "Adding Sugar and Milk" << std::endl; }
    bool customerWantsCondiments() override { return false; }
};

#endif
