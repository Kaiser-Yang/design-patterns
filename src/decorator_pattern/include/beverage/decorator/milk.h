#ifndef DESIGN_PATTERNS_MILK_H
#define DESIGN_PATTERNS_MILK_H

#include <memory>

#include "beverage/beverage.h"
#include "condiment_decorator.h"

class Milk : public CondimentDecorator {
public:
    Milk(std::unique_ptr<Beverage> beverage) : CondimentDecorator(std::move(beverage)) {
        description = this->beverage->getDescription() + ", Milk";
    }

    double cost() const override { return beverage->cost() + 0.10; }
};

#endif
