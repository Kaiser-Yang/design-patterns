#ifndef DESIGN_PATTERNS_WHIP_H
#define DESIGN_PATTERNS_WHIP_H

#include <memory>

#include "condiment_decorator.h"

class Whip : public CondimentDecorator {
public:
    Whip(std::unique_ptr<Beverage> beverage) : CondimentDecorator(std::move(beverage)) {
        description = this->beverage->getDescription() + ", Whip";
    }

    double cost() const override { return beverage->cost() + 0.10; }
};

#endif
