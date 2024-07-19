#ifndef DESIGN_PATTERNS_SOY_H
#define DESIGN_PATTERNS_SOY_H

#include <memory>

#include "condiment_decorator.h"

class Soy : public CondimentDecorator {
public:
    Soy(std::unique_ptr<Beverage> beverage) : CondimentDecorator(std::move(beverage)) {
        description = this->beverage->getDescription() + ", Soy";
    }

    double cost() const override { return beverage->cost() + 0.15; }
};

#endif
