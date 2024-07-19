#ifndef DESIGN_PATTERNS_HOUSE_BLEND_H
#define DESIGN_PATTERNS_HOUSE_BLEND_H

#include "beverage.h"

class HouseBlend : public Beverage {
public:
    HouseBlend() { description = "House Blend Coffee"; }
    double cost() const override { return 0.89; }
};

#endif
