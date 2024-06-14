#ifndef DESIGN_PATTERNS_CONDIMENT_DECORATOR_H
#define DESIGN_PATTERNS_CONDIMENT_DECORATOR_H

#include <memory>

#include "beverage/beverage.h"

class CondimentDecorator : public Beverage {
public:
    CondimentDecorator(std::unique_ptr<Beverage> beverage) : beverage(std::move(beverage)) {}

protected:
    std::unique_ptr<Beverage> beverage;
};

#endif
