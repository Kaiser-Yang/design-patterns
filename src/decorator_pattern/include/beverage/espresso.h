#ifndef DESIGN_PATTERNS_ESPRESSO_H
#define DESIGN_PATTERNS_ESPRESSO_H

#include "beverage.h"

class Espresso : public Beverage {
public:
    Espresso() { description = "Espresso"; }
    double cost() const override { return 1.99; }
};

#endif
