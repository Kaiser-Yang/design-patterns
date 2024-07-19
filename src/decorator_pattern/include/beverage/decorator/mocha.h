#ifndef DESIGN_PATTERNS_MOCHA_H
#define DESIGN_PATTERNS_MOCHA_H

#include <memory>

#include "condiment_decorator.h"

class Mocha : public CondimentDecorator {
public:
    Mocha(std::unique_ptr<Beverage> beverage) : CondimentDecorator(std::move(beverage)) {
        description = this->beverage->getDescription() + ", Mocha";
    }

    double cost() const override { return beverage->cost() + 0.20; }
};

#endif
