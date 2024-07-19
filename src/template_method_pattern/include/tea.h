#ifndef DESIGN_PATTERNS_TEA_H
#define DESIGN_PATTERNS_TEA_H

#include "caffeine_beverage.h"

class Tea : public CaffeineBeverage {
public:
    void brew() override { std::cout << "Steeping the tea" << std::endl; }
    void addCondiments() override { std::cout << "Adding Lemon" << std::endl; }
};

#endif
