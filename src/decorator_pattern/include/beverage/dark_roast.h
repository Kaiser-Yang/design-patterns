#ifndef DESIGN_PATTERNS_DARK_ROAST_H
#define DESIGN_PATTERNS_DARK_ROAST_H

#include "beverage.h"

class DarkRoast : public Beverage {
public:
    DarkRoast() { description = "Dark Roast Coffee"; }
    double cost() const override { return 0.99; }
};

#endif
