#ifndef DESIGN_PATTERNS_CAFFEINE_BEVERAGE_H
#define DESIGN_PATTERNS_CAFFEINE_BEVERAGE_H

#include <iostream>

class CaffeineBeverage {
public:
    virtual void prepareRecipe() final {
        boilWater();
        brew();
        pourInCup();
        if (customerWantsCondiments()) { addCondiments(); }
    }
    virtual void brew()          = 0;
    virtual void addCondiments() = 0;
    virtual void boilWater() { std::cout << "Boiling water" << std::endl; }
    virtual void pourInCup() { std::cout << "Pouring into cup" << std::endl; }
    virtual bool customerWantsCondiments() { return true; }
};

#endif
